#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	vector<pii> cors[n + 1];
	int take = 1;
	int u, v;
	for(int i = 1; i <= m ; i ++ ){
		cin >> u >> v;
		cors[u].push_back(mp(u, take));
		cors[v].push_back(mp(v, take));
		take ++ ;
	}
	for(int i = 1; i <= n; i ++ ){
		cors[i].push_back(mp(i, take));
		take ++ ;
	}
	for(int i = 1; i <= n; i ++ ){
		cout << cors[i].size() << "\n";
		for(auto x : cors[i])
			cout << x.fi << " " << x.se << "\n";
	}
	return 0;
}