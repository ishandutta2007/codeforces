#include<assert.h>
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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }


int N;
LL R;
int L[200111], T[200111];

LL ans;
vector<LL> ansV;

int main() {

    scanf("%d%lld", &N, &R);

    REP (i, N) scanf("%d", L+i);
    REP (i, N) scanf("%d", T+i);

    bool yes = true;
    REP (i, N) if (L[i] > T[i]) yes = false;

    if (yes) {
	LL cur = 0;
	LL last = 0;
	REP (i, N) {
//	    eprintf("%lld %lld\n", cur, last);
	    if (last >= L[i]) {
		cur += L[i];
		last -= L[i];
	    } else if (2 * L[i] - last <= T[i]) {
		cur += 2 * L[i] - last;
		last = 0;
	    } else {
		LL x = 2 * L[i] - last - T[i];

		LL y = (x + R - 1) / R;
		if ((int)ansV.size() <= 100111) {
		    for (int k=0; k<y && (int)ansV.size() <= 100111; k++) {
			ansV.push_back(cur + 2 * L[i] - last - 2 * x + k * R);
		    }
		}

		cur += T[i];
		ans += y;
		last = y * R - x;
	    }
	}

	printf("%lld\n", ans);
	if (ans <= 100000) {
	    REP (i, ans) printf("%lld%c", ansV[i], i==ans-1? '\n': ' ');
	    if (ans == 0) putchar('\n');
	}

    } else {
	puts("-1");
    }

    return 0;
}