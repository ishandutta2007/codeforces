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
char S[100111];

int main() {
    scanf("%d%s", &N, S);
    int LEN = strlen(S);

    LL ans = 0;
    LL Np = 1;

    for (int i=LEN; i;) {
	LL ten = 1;
	LL cur = 0;
	int j = i;
	while (0 < j && (S[j-1]-'0') * ten + cur < N && ten < N) {
	    j--;
	    cur += (S[j]-'0') * ten;
	    ten *= 10;
	}

	while (j < i-1 && S[j] == '0') {
	    ten /= 10;
	    cur -= (S[j]-'0') * ten;
	    j++;
	}

	ans += Np * cur;
	Np *= N;

	i = j;
    }


    printf("%lld\n", ans);

    return 0;
}