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

int N, T;
double D[15][15];


int main() {
    scanf("%d%d", &N, &T);
    D[0][0] += T;
    int ans = 0;
    REP (i, N) {
	REP (j, i+1) {
	    if (D[i][j] >= 1.0) {
		ans++;
		double x = D[i][j] - 1.0;
		D[i+1][j] += x / 2;
		D[i+1][j+1] += x / 2;
	    }
	}
    }

    printf("%d\n", ans);


    return 0;
}