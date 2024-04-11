//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 2000 + 10;
LL sum[4][maxn][maxn], a[maxn][maxn];
int n;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", a[i] + j);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			sum[0][i][j] = sum[0][i - 1][j - 1] + a[i - 1][j - 1];
	for(int i = 1; i <= n; i++)
		for(int j = n; j >= 1; j--)
			sum[1][i][j] = sum[1][i - 1][j + 1] + a[i - 1][j + 1];
	for(int i = n; i >= 1; i--)
		for(int j = 1; j <= n; j++)
			sum[2][i][j] = sum[2][i + 1][j - 1] + a[i + 1][j - 1];
	for(int i = n; i >= 1; i--)
		for(int j = n; j >= 1; j--)
			sum[3][i][j] = sum[3][i + 1][j + 1] + a[i + 1][j + 1];
	int x = 0, y = 0, xx = 0, yy = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			for(int k = 1; k < 4; k++)
				sum[0][i][j] += sum[k][i][j];
			sum[0][i][j] += a[i][j];
			if((i + j) & 1){
				if(sum[0][i][j] >= sum[0][x][y])
					x = i, y = j;
			}
			else if(sum[0][i][j] >= sum[0][xx][yy])
				xx = i, yy = j;
		}
	printf("%I64d\n%d %d %d %d", sum[0][x][y] + sum[0][xx][yy], x, y, xx, yy);
	return 0;
}