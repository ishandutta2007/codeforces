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

int N;
int F[111][111];
int main() {
    scanf("%d", &N);
    REP (i, N) {
	int x, y, x1, y1;
	scanf("%d%d%d%d", &x, &y, &x1, &y1);
	y1++; x1++;
	F[x][y]++;
	F[x][y1]--;
	F[x1][y]--;
	F[x1][y1]++;
    }

    int ans = 0;
    REP (i, 110) REP (j, 110) {
	F[i+1][j+1] -= F[i][j];
	F[i][j+1] += F[i][j];
	F[i+1][j] += F[i][j];
	ans += F[i][j];
    }

    printf("%d\n", ans);
    return 0;
}