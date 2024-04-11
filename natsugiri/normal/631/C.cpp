#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, M;
int A[200111];
int B[200111];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);

    vector<pair<int, int> > S;
    REP (i, M) {
	int t, r;
	scanf("%d%d", &t, &r);
	while (!S.empty() && S.back().second< r) S.pop_back();
	S.push_back(make_pair(t, r));
    }


    int start = 0, end = N-1;
    int cur = N-1;
    bool rev = false;

    if (S.size()) {
	sort(A, A+S[0].second);
    }

    EACH (e, S) {
	int t = e->first;
	int r = e->second;

	while (r <= cur) {
	    if (rev) {
		B[cur] = A[start];
		start++;
		cur--;
	    } else {
		B[cur] = A[end];
		end--;
		cur--;
	    }
	}

	rev = (t == 2);
    }
    
    while (0 <= cur) {
	if (rev) {
	    B[cur] = A[start];
	    start++;
	    cur--;
	} else {
	    B[cur] = A[end];
	    end--;
	    cur--;
	}
    }

    REP (i, N) printf("%d%c", B[i], i==N-1?'\n':' ');



    return 0;
}