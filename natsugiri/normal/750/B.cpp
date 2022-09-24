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
int X;
char dir[1001];

int main() {
    scanf("%d", &N);
    int sum = 0;
    bool yes = true;

    REP ($, N) {
	scanf("%d%s", &X, dir);

	if (dir[0] != 'S' && sum == 0) yes = false;
	if (dir[0] != 'N' && sum == 20000) yes = false;

	if (dir[0] == 'S') sum += X;
	if (dir[0] == 'N') sum -= X;

	if (sum < 0 || 20000 < sum) yes = false;
    }

    if (sum != 0) yes = false;

    puts(yes? "YES": "NO");

    return 0;
}