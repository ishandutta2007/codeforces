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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

char F[1<<9][(1<<9)+1];
inline X(char c) {
    if (c == '+') return '*';
    else return '+';
}
int K;
int main() {
    F[0][0] = '+';
    scanf("%d", &K);
    REP (i, K) {
	int s = 1<<i;
	REP (y, s) REP (x, s) {
	    F[y][x+s] = F[y+s][x] = F[y][x];
	    F[y+s][x+s] = X(F[y][x]);
	}
    }

    REP (i, 1<<K) puts(F[i]);
    return 0;
}