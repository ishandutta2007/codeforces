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

int N;
int Ax, Ay;
int Bx, By;
int Cx, Cy;

bool ord(int a, int b, int c) {
    if (a < b && b < c) return true;
    if (a > b && b > c) return true;
    return false;
}

void MAIN() {
    scanf("%d", &N);
    scanf("%d%d%d%d%d%d", &Ax, &Ay, &Bx, &By, &Cx, &Cy);

    bool yes = true;
    if (ord(Bx, Ax, Cx)) yes = false;
    if (ord(By, Ay, Cy)) yes = false;

    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}