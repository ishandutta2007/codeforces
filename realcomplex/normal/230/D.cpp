#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double db;

#define fi first
#define se second
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())
#define mp make_pair

const int N = (int)1e5 + 9;
vector<pii> T[N];

int d[N];

vector<int> P[N];
vector<int> nx[N];

int fin(int h, int d){
	int y = lower_bound(P[h].begin(), P[h].end(), d) - P[h].begin();
	if(y >= P[h].size() or P[h][y] != d)
		return d;
	return nx[h][y];
}

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	int a, b, c;
	for(int i = 0 ;i  < m ;i ++ ){
		cin >> a >> b >> c;
		T[a].push_back(mp(b, c));
		T[b].push_back(mp(a, c));
	}
	for(int i = 1; i <= n;i ++ )
		d[i] = (int)2e9 + 9;
	int k;
	for(int i = 1; i <= n; i ++ ){
		cin >> k;
		for(int j = 0 ; j < k ;j ++ ){
			cin >> b;
			P[i].push_back(b);
			nx[i].push_back(b + 1);
		}
		for(int j = k - 2; j >= 0 ; j -- ){
			if(P[i][j] + 1 == P[i][j + 1]){
				nx[i][j] = nx[i][j + 1]; 
			}
		}
	}
	priority_queue<pii, vector<pii>, greater<pii>> g;
	d[1] = fin(1, 0);
	g.push(mp(d[1], 1));	
	int nd;
	int dd;
	int ff;
	while(!g.empty()){
		nd = g.top().se;
		dd = g.top().fi;
		g.pop();
		if(dd != d[nd]){
			continue;
		}
		for(auto x : T[nd]){
			ff = fin(x.fi, dd + x.se);
			if(x.fi == n){
				if(dd + x.se < d[x.fi]){
					d[x.fi] = dd + x.se;
					g.push(mp(d[x.fi], x.fi));
				}
			}
			else if(ff < d[x.fi]){
				d[x.fi] = ff;
				g.push(mp(d[x.fi], x.fi));
			}
		}
	}
	cout << (d[n] == (int)2e9 + 9 ? -1 : d[n]) << "\n";
	return 0;
}