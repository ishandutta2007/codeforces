#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
int A[511];
int B[511];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);

    A[N] = B[N] = N + 1;
    int prv = -1;
    vector<pair<int, int> > A2;
    REP (i, N+1) {
	A2.emplace_back(min(prv, A[i]), max(prv, A[i]));
	prv = A[i];
    }

    prv = -1;
    vector<pair<int, int> > B2;
    REP (i, N+1) {
	B2.emplace_back(min(prv, B[i]), max(prv, B[i]));
	prv = B[i];
    }

    sort(A2.begin(), A2.end());
    sort(B2.begin(), B2.end());

    if (A2 == B2) {

	vector<pair<int, int> > ans;
	auto PUSH = [&](int l, int r) {
	    reverse(A+l, A+r);
	    ans.emplace_back(l, r);
	};

	for (int i=0; i<N-1; i++) {
	    if (A[i+1] == B[i+1]) {
		continue;
	    } else {
		bool ok = false;
		for (int j=i+2; j<N; j++) {
		    if (A[j] == B[i+1]) {
			if (A[j+1] != A[i] && A[j-1] == A[i]) {
			    // A[i: j) x A[j: N);
			    map<int, int> mp;
			    for (int k=i; k<j; k++) mp[A[k]] = k;
			    for (int k=j; k<N; k++) {
				auto it = mp.find(A[k]);
				if (it != mp.end()) {
				    int x = it->second;
				    // A[x: k];
				    PUSH(x, k+1);
				    j = k-j+x;
				    break;
				}
			    }
			}
			if (A[j+1] == A[i]) {
			    PUSH(i, j+2);
			    ok = true;
			    break;
			}
		    }
		}

		if (!ok) {
		    puts("NO");
		    assert(false);
		    return;
		}
	    }
	}

	puts("YES");
	printf("%d\n", (int)ans.size());
	EACH (e, ans) printf("%d %d\n", e->first+1, e->second);

    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}