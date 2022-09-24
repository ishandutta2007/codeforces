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

int H, W;
char F[555][555];
int DV[555][555], DH[555][555];
int Q;
int R1, C1, R2, C2;

int main() {
    scanf("%d%d", &H, &W);
    REP (i, H) scanf("%s", F[i]);

    REP (i, H+1) REP (j, W+1) {
	DH[i+1][j] += DH[i][j];
	DH[i][j+1] += DH[i][j];
	DH[i+1][j+1] -= DH[i][j];
	DV[i+1][j] += DV[i][j];
	DV[i][j+1] += DV[i][j];
	DV[i+1][j+1] -= DV[i][j];

	if (F[i][j] == '.' && F[i][j+1] == '.') DH[i+1][j+2]++;
	if (F[i][j] == '.' && F[i+1][j] == '.') DV[i+2][j+1]++;
    }

    scanf("%d", &Q);
    REP ($, Q) {
	scanf("%d%d%d%d", &R1, &C1, &R2, &C2);

	int ans = 0;
	ans += DH[R2][C2] - DH[R1-1][C2] - DH[R2][C1] + DH[R1-1][C1];
	ans += DV[R2][C2] - DV[R1][C2] - DV[R2][C1-1] + DV[R1][C1-1];
	printf("%d\n", ans);
    }

    return 0;
}