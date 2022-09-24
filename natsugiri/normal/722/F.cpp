#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }


int N, M;

int ans[100111];

struct Data {
    int pos;
    ULL mask[41]; // 32 ~ 40
};
vector<Data> D[100111];
ULL acc[17][100111];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	int l;
	scanf("%d", &l);

	REP (j, l) {
	    int x;
	    scanf("%d", &x);

	    Data d;
	    d.pos = i;
	    for (int t=1; t<=40; t++) {
		int g = __gcd(l, t);
		d.mask[t] = 0;
		REP (u, t) {
		    if (abs(j - u) % g == 0) {
			d.mask[t] |= 1LL << u;
		    }
		}
	    }

	    D[x].push_back(d);
	}

    }


    REP (k, M+1) {
	if (D[k].size() == 0u) continue;

	VI least(D[k].size(), N);

	for (int cycle=1; cycle<=40; cycle++) {
	    // table
	    REP (i, D[k].size())
		acc[0][i] = D[k][i].mask[cycle];

	    REP (t, 16) {
		REP (i, D[k].size()) {
		    if (i + (1 << t) >= (int)D[k].size()) continue;
		    acc[t+1][i] = acc[t][i] & acc[t][i + (1 << t)];
		}
	    }

	    // binary search
	    REP (i, D[k].size()) {
		int R = i;

		for (int w=17; w--;) {
		    int ww = 1 << w;

		    bool yes = false;
		    if (R + ww <= (int)D[k].size() && 
			    D[k][R+ww-1].pos - D[k][i].pos == R + ww - 1 - i) {

			yes = true;
			// [i, R + ww)
			int lg = __lg(R + ww - i);
			LL and_0 = acc[lg][i] & acc[lg][R + ww - (1 << lg)];
			if (and_0 == 0) {
			    yes = false;
			}
		    }

		    if (yes) R += ww;
		}
		amin(least[i], R - i);
	    }
	}

	ans[k] = *max_element(least.begin(), least.end());
//	eprintf("%d : ", k);
//	EACH (e, least) eprintf(" %d", *e); eprintf("\n");
//

    }



    REP (i, M) printf("%d\n", ans[i+1]);
    return 0;
}