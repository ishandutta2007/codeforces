#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t, a, b, c;
ll arr[200005];
ll dp[200005];

vector<ll> v[200005];

ll ans = 0;

void dfs(int x, ll num) {
	ll sz = v[x].size();
	
	ans += arr[x] * num;
	
	if (sz == 0) dp[x] = arr[x];
	
	if (sz != 0){
		ll num1 = num / sz;
		ll num2 = num % sz;
		
		vector<ll> v1;
		
		for (auto it : v[x]) {
			dfs(it, num1);
			v1.pb(dp[it]);
		}
		
		sort(all(v1));
		ll sz1 = v1.size();
		for (int i = sz1-1; i>=sz1-num2; i--) {
			ans += v1[i];
		}
		
		dp[x] = arr[x] + v1[sz1-num2-1];
	}
	
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n >> m;
		for (int i=0; i<=n; i++) {
			v[i].clear();
			dp[i] = 0;
		}
		for (int i=0; i<n-1; i++) {
			cin >> a;
			v[a].pb(i+2);
		}
		for (int i=0; i<n; i++) {
			cin >> arr[i+1];
		}
		dfs(1, m);
		
		cout << ans << nl;
	}
}