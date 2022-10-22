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

ll n, m, t, cn;
int e[200015];
int idx1[200005];
int idx[200005];
int cnt[200005];
vector<pll> v[200005];
bool vis[200005];
set<int> s;
int pre[200005];
int pos[200005];

void dfs(ll x, ll par){
	vis[x] = true;
	pre[x] = cn++;
	for (auto it : v[x]) {
		if (it.first == par) continue;
		if (vis[it.first] && pre[it.first] > pre[x]){
			e[it.second] = 0;
			idx1[x] = it.second;
			s.insert(x);
			s.insert(it.first);
			cnt[x]++;
		}
		else if (!vis[it.first]) {
			idx[x] = it.second;
			e[it.second] = 1;
			dfs(it.first, x);
		}
	}
	pos[x] = cn-1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cn = 1;
		for (int i = 0; i<= n; i++){
			v[i].clear();
			vis[i] = false;
			cnt[i] = 0;
			idx[i] = 0;
			idx1[i] = 0;
		}
		s.clear();
		for (int i=1; i<=m; i++) {
			ll a, b;
			cin >> a >> b;
		//	cin >> e[i].first >> e[i].second;
			v[a].pb(mp(b, i));
			v[b].pb(mp(a, i));
		}
		

		
		dfs(1, -1);
		
		if (m == n+2) {
			if (s.size() == 3){
				for (int i=1; i<=n; i++){
					if (cnt[i] == 2){
						ll a;
						for (auto it : v[i]){
							if (it.second == idx1[i]) a = pre[it.first];
						}
						for (auto it : v[i]){
							if (pre[it.first] < pre[i]) continue;
							if (a <= pos[it.first] && a >= pre[it.first]){
								e[it.second] = 0;
							}
						}
						e[idx1[i]] = 1;
					}
				}
			}
		}
		
		for (int i = 1; i<=m; i++){
			cout << e[i];
		}
		cout << nl;
	}
}