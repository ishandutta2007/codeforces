#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t;
ll arr[100005];
vector<int> v[100005];

void dfs(int x, int p, int col){
	ll sz = v[x].size();
	arr[x] = sz*col;
	for (auto it : v[x]){
		if (it == p) continue;
		dfs(it, x, -col);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=1; i<=n; i++){
			v[i].clear();
		}
		for (int i=0; i<n-1; i++){
			int a, b;
			cin >> a >> b;
			v[a].pb(b);
			v[b].pb(a);
		}
		dfs(1, -1, 1);
		for (int i=1; i<=n; i++){
			cout << arr[i] << " ";
		}
		cout << nl;
	}
}