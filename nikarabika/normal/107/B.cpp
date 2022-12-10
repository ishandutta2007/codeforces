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

const int maxn = 1e5 + 5,
	  maxk = 100 + 5;
LD dp[maxk][maxn];
int a[maxn],
	su, n, m, h;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> h, h--, n--;
	for(int i = 0; i < m; i++)
		cin >> a[i], su += a[i];
	a[h]--;
	su--;
	if(su < n){
		cout << -1 << endl;
		return 0;
	}
	if(su - a[h] < n){
		cout << 1 << endl;
		return 0;
	}
	dp[0][0] = 1;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j < su; j++){
			LD p = LD(n - i) / LD(su - j);
			dp[i + 0][j + 1] += dp[i][j] * (1 - p);
			dp[i + 1][j + 1] += dp[i][j] * p;
		}
	int x = su - a[h],
		y = su;
	LD ans = dp[n][x] / dp[n][y];
	/*cout << x << ' ' << y << endl;
	for(int i = x + 1; i <= y; i++)
		ans *= LD(i - n) / LD(i);*/
	cout.precision(15);
	cout << fixed << 1 - ans << '\n';
	return 0;
}