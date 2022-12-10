#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 2e5 + 85 - 69;
vector<pair<pair<LL, int>, int> > adj[maxn];
LL dist[maxn];
vector<int> positions, ans;
set<pie> s;
int n, l;
int x[maxn], d[maxn], t[maxn], p[maxn], par[maxn], number[maxn];
bool unusable[maxn];

void Dijkstra(int source){
	memset(dist, 127, sizeof dist);
	dist[source] = 0;
	s.insert(MP(0, source));
	while(s.size()){
		int x = s.begin()->R;
		s.erase(s.begin());
		for(int i = 0; i < adj[x].size(); i++){
			if(dist[x] + adj[x][i].R < dist[adj[x][i].L.L]){
				s.erase(MP(dist[adj[x][i].L.L], adj[x][i].L.L));
				dist[adj[x][i].L.L] = dist[x] + adj[x][i].R;
				par[adj[x][i].L.L] = x;
				number[adj[x][i].L.L] = adj[x][i].L.R;
				s.insert(MP(dist[adj[x][i].L.L], adj[x][i].L.L));
			}
		}
	}
}

void make(int x){
	if(number[x] != 0)
		ans.PB(number[x]);
	if(x == 0)
		return;
	make(par[x]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> d[i] >> t[i] >> p[i];
		if(x[i] < p[i]){
			unusable[i] = true;
			continue;
		}
		positions.PB(x[i] - p[i]);
		positions.PB(x[i] + d[i]);
	}
	positions.PB(0);
	positions.PB(l);
	sort(positions.begin(), positions.end());
	positions.resize(unique(positions.begin(), positions.end()) - positions.begin());
	for(int i = 0; i + 1 < positions.size(); i++){
		adj[i].PB(MP(MP(i + 1, 0), positions[i + 1] - positions[i]));
		adj[i + 1].PB(MP(MP(i, 0), positions[i + 1] - positions[i]));
	}
	for(int i = 0; i < n; i++) if(!unusable[i]){
		int id_begin = lower_bound(positions.begin(), positions.end(), x[i] - p[i]) - positions.begin(),
			id_end = lower_bound(positions.begin(), positions.end(), x[i] + d[i]) - positions.begin();
		adj[id_begin].PB(MP(MP(id_end, i + 1), p[i] + t[i]));
	}
	Dijkstra(0);
	cout << dist[positions.size() - 1] << endl;
	make(positions.size() - 1);
	cout << ans.size() << endl;
	for(int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}