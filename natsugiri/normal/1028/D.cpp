#include<set>
#include<cassert>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

const LL MOD = 1e9+7;

int N;
vector<char> ACC;
VI P;

void MAIN() {
    scanf("%d", &N);
    ACC.reserve(N);
    P.reserve(N);

    REP (i, N) {
	char op[111];
	int p;
	scanf("%s%d", op, &p);
	ACC.push_back(op[1]);
	P.push_back(p);
    }

    LL ans = 1;

    set<int> S, U, B;
    REP (i, N) {
	if (ACC[i] == 'D') {

	    int s_low = MOD;
	    if (!S.empty()) s_low = *S.begin();

	    int b_high = -MOD;
	    if (!B.empty()) b_high = *B.rbegin();

//	    eprintf("%d %d\n", s_low, b_high);
	    if (b_high < P[i] && P[i] < s_low) {
		U.insert(P[i]);
	    } else if (b_high < P[i]) {
		S.insert(P[i]);
	    } else if (P[i] < s_low) {
		B.insert(P[i]);
	    } else {
		assert(false);
	    }
	} else {
	    do {
		{
		    auto it = U.find(P[i]);
		    if (it != U.end()) {
			ans += ans;
			if (ans >= MOD) ans -= MOD;

			EACH (e, U) {
			    if (*e < P[i]) B.insert(*e);
			    else if (P[i] < *e) S.insert(*e);
			}
			U.clear();
			break;
		    }
		}

		EACH (e, U) {
		    if (*e < P[i]) B.insert(*e);
		    else if (P[i] < *e) S.insert(*e);
		}
		U.clear();

		{
		    auto it = S.find(P[i]);
		    if (it != S.end()) {
			if (P[i] != *S.begin()) {
			    ans = 0;
			    goto END;
			}
			S.erase(it);
			break;
		    }
		}
		{
		    auto it = B.find(P[i]);
		    if (it != B.end()) {
			if (P[i] != *B.rbegin()) {
			    ans = 0;
			    goto END;
			}
			B.erase(it);
			break;
		    }
		}

		assert(false);
	    } while (0);
	}
    }

END:;

    ans *= (int)U.size() + 1;
    ans %= MOD;
    if (ans < 0) ans += MOD;


    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}