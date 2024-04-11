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

ll n, m, t, p[200005], val[200005];
ll l[200005], r[200005];
ll cnt;
vector<int> v[200005];

void dfs(int x){
	val[x] = 0;
	ll sum = 0;
	for (auto it : v[x]){
		dfs(it);
		sum += val[it];
	}
	if (sum < l[x]){
		cnt++;
		val[x] = r[x];
	}
	else {
		val[x] = min(sum, r[x]);
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
		for (int i=2; i<=n; i++){
			cin >> p[i];
			v[p[i]].pb(i);
		}
		cnt = 0;
		for (int i=1; i<=n; i++){
			cin >> l[i] >> r[i];
		}
		dfs(1);
		cout << cnt << nl;
	}
	
}