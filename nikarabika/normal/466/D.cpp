//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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
const LL Mod = 1000 * 1000 * 1000 + 7;
//LL dp[maxn][maxn];
int a[maxn],
	n, h;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> h;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = h - a[i];
	}
	for(int i = 1; i <= n + 1; i++)
		if(a[i] < 0 or abs(a[i] - a[i - 1]) > 1){
			cout << 0;
			return 0;
		}
	LL dp = 1;
	for(int i = 1; i <= n; i++)
		if(a[i] - a[i - 1] == 0)
			dp = ((a[i - 1] + 1) * dp) % Mod;
		else if(a[i] - a[i - 1] == -1)
			dp = (a[i - 1] * dp) % Mod;
	cout << dp << endl;
	return 0;
}