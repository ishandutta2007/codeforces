#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b;

vector<int> v[200005];

ll ans[200005];
bool fin[200005], vis[200005];

bool gd = true;

void dfs(int x){
	fin[x] = 0;
	vis[x] = 1;
	if (v[x].empty()){
		ans[x] = 1;
	}
	else {
		for (auto it: v[x]){
			if (!fin[it] && vis[it]) gd = true;
			else if (ans[it] != 0){
				if (it < x) ans[x] = max(ans[x], ans[it]);
				else ans[x] = max(ans[x], ans[it] + 1);
			}
			else {
				dfs(it);
				if (it < x) ans[x] = max(ans[x], ans[it]);
				else ans[x] = max(ans[x], ans[it] + 1);
			}
		}
	}
	fin[x] = 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int tc = 1; tc <= t; tc++){
		cin >> n;
		gd = false;
		for (int i=1; i<=n; i++){
			v[i].clear();
			ans[i] = 0;
			fin[i] = false;
			vis[i] = false;
		}
		for (int i=1; i<=n; i++){
			cin >> a;
			for (int j=0; j<a; j++){
				cin >> b;
				v[i].pb(b);
			}
		}
		for (int i=1; i<=n; i++){
			if (gd) continue;
			if (ans[i] != 0) continue;
			dfs(i);
		}
		if (gd) cout << "-1\n";
		else {
			ll ans1 = 0;
			for (int i=1; i<=n; i++){
				ans1 = max(ans1, ans[i]);
			}
			cout << ans1 << "\n";
		}
	}
}