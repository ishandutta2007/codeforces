//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;
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

const int maxn = 300 + 10;
LD dp[maxn][maxn][maxn];
int r, s, p;

LD P(int su, int c1, int c2){
	int c3 = su - c1 - c2;
	return LD(c1 * c2) / LD(c1 * c2 + c2 * c3 + c1 * c3);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> s >> p;
	dp[r][s][p] = 1;
	for(int su = r + s + p; su; su--){
		for(int i = 0; i <= su; i++){
			for(int j = 0; j <= su - i; j++){
				int k = su - (i + j);
				if(i and j)
					dp[i][j - 1][k] += dp[i][j][k] * P(su, i, j);
				if(i and k)
					dp[i - 1][j][k] += dp[i][j][k] * P(su, i, k);
				if(j and k)
					dp[i][j][k - 1] += dp[i][j][k] * P(su, j, k);
			}
		}
	}
	LD ans[3] = {0, 0, 0};
	for(int i = 1; i < maxn; i++){
		ans[0] += dp[i][0][0];
		ans[1] += dp[0][i][0];
		ans[2] += dp[0][0][i];
	}
	cout.precision(15);
	for(int i = 0; i < 3; i++)
		cout << fixed << ans[i] << ' ';
	cout << endl;
	return 0;
}