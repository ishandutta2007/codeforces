#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, a, b, leaf, bud;
bool yeet[200005];
vector<int> v[200005];

void dfs(int x, int par){
	int cur = 0;
	for (auto it : v[x]){
		if (it == par) continue;
		dfs(it, x);
		if (!yeet[it]) cur++;
	}
	if (!cur) leaf++; 
	else if (x!=1) {
		yeet[x] = true;
		bud++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int tc=0; tc<t; tc++){
		cin >> n;
		for (int i=1; i<=n; i++){
			v[i].clear();
			yeet[i] = false;
		}
		for (int i=1; i<n; i++){
			cin >> a >> b;
			v[a].pb(b);
			v[b].pb(a);
		}
		bud = leaf = 0;
		dfs(1, -1);
		cout << leaf - bud << "\n";
	}
}