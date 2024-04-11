#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c, arr[200005], bruh[200005];
bool vis[200005];
ll dp[505][505];
ll x[200005], y[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n; i++){
		cin >> x[i] >> y[i];
	}
	ll cc = 0;
	for (int i=1; i<=m; i++){
		cin >> b >> a;
		for (int j=2; j<500; j++){
			cc += dp[i%j][j];
		}
		cc += bruh[i];
//		cout << cc << "\n";
		if (b == 2){
			vis[a] = false;
			ll s1 = x[a] + y[a];
			ll xx = (arr[a] + x[a])%s1;
			ll yy = arr[a]%s1;
			ll zz = i%s1;
			if (yy < xx) yy += s1;
			if (zz < xx) zz += s1;
			if (zz < yy && zz >= xx) cc--;
			if (x[a]+y[a] < 500){
				ll s = x[a] + y[a];
				dp[arr[a]%s][s]++;
				dp[(arr[a]+x[a])%s][s]--;
			}
			else {
				ll cnt = 1, cur = arr[a];
				while (true){
					cur += x[a];
					if (cur > m) break;
					bruh[cur]--;
					cur += y[a];
					if (cur > m) break;
					bruh[cur]++;
				}
			}
		}
		else {
			vis[a] = true;
			arr[a] = i;
			if (x[a]+y[a] < 500){
				ll s = x[a] + y[a];
				dp[i%s][s]--;
				dp[(i+x[a])%s][s]++;
			}
			else {
				ll cnt = 1, cur = arr[a];
				while (true){
					cur += x[a];
					if (cur > m) break;
					bruh[cur]++;
					cur += y[a];
					if (cur > m) break;
					bruh[cur]--;
				}
			}
		}
		cout << cc << "\n";
	}
}