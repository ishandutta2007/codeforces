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

const int maxn = 1e6 + 85 - 69;
const LL Mod = 1e9 + 7;
LL a[maxn];
LL dp[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], a[i]--;
	a[n] = Mod;
	if(n == 1){
		cout << a[0] << endl;
		return 0;
	}
	for(int i = n - 1; i > 0; i--){
		dp[i] = min(a[i - 1], min(a[i], a[i + 1])) * dp[i + 1] + min(a[i], a[i - 1]);
		dp[i] %= Mod;
	}
	LL ans = 0;
	for(int i = 0; i < n; i++)
		ans = (ans + min(a[i], a[i + 1]) * dp[i + 1] + a[i]) % Mod;
	cout << ans << endl;
	return 0;
}