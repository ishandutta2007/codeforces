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

int Hy, Ay, Dy;
int Hm, Am, Dm;
int Hp, Ap, Dp;

int main() {
    scanf("%d%d%d", &Hy, &Ay, &Dy);
    scanf("%d%d%d", &Hm, &Am, &Dm);
    scanf("%d%d%d", &Hp, &Ap, &Dp);

    int ans = 1000000000;
    for (int a=Ay; a<=200; a++) for (int d=Dy; d<=100; d++) {
	if (a <= Dm) continue;
	int x = a - Dm;
	int t = (Hm + x - 1) / x;
	int h = max(Hy, max(0, Am - d) * t + 1);
	amin(ans, Ap * (a - Ay) + Dp * (d - Dy) + Hp * (h - Hy));
    }
    printf("%d\n", ans);

    return 0;
}