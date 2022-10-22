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

ll n, m, t;

vector<pii> v[105][105];

string arr[105][105];

ll cnt = 0, cnt1 = 0;
bool vis[105];
bool vis1[105][105];
ll dist[105][105];
vector<pii> v1;
vector<int> v2[105];

void dfs(pii p){
	cnt++;
	v1.pb(p);
	vis1[p.first][p.second] = 1;
	ll x = p.first, y = p.second;
	if (!vis[x]){
		vis[x] = 1;
		cnt1++;
	}
	if (!vis[y]){
		vis[y] = 1;
		cnt1++;
	}
	for (auto it : v[x][y]){
		if (vis1[it.first][it.second]) continue;
		dfs(it);
	}
}

void dfs2(int x, int par, int d, int y){
	dist[y][x] = d;
	for (auto it : v2[x]){
		if (it == par) continue;
		dfs2(it, x, d+1, y);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		bool ch = true;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				v[i][j].clear();
			}
		}
		for (int i=1; i<=n-1; i++){
			for (int j=1; j<=n-i; j++){
				string s;
				cin >> arr[i][j];
				for (int k=0; k<n; k++){
					if (arr[i][j][k] == '1'){
						ll b = min(i+j, k+1), d= max(i+j,k+1), a = min(i,k+1), c = max(i,k+1);
						v[a][c].pb(mp(b,d));
						v[b][d].pb(mp(a,c));
					}
				}
			}
		}
		for (int l=2; l<=n; l++){
			cnt = cnt1 = 0;
			for (int i=1; i<=n; i++){
				vis[i] = 0;
				for (int j=1; j<=n; j++){
					vis1[i][j] = 0;
				}
			}
			v1.clear();
			dfs(mp(1,l));
			if (cnt1 != n || cnt != n-1) continue;
			for (int j=1; j<=n; j++){
				v2[j].clear();
			}
		//	cout << l << " test\n";
			for (auto it : v1){
				v2[it.first].pb(it.second);
				v2[it.second].pb(it.first);
			}
			for (int i=1; i<=n; i++){
				dfs2(i,-1,0,i);
			}
			bool gd=true;
			for (int i=1; i<=n-1; i++){
				for (int j=1; j<=n-i; j++){
					for (int k=0; k<n; k++){
						if (arr[i][j][k] == '0'){
							if (dist[i][k+1] == dist[i+j][k+1]) gd = false;
						}
						else {
							if (dist[i][k+1] != dist[i+j][k+1]) gd= false;
						}
					}

				}
			}
			if (gd){
				cout << "Yes\n";
				for (auto it : v1){
					cout << it.first << " " << it.second << "\n";
				}
				ch = false;
				break;
			}
		}
		if (ch) cout << "No\n";
	}
}