//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 3000;
bitset<maxn> adj[maxn];
int dis[maxn][maxn];
int n;
int x[maxn],
   y[maxn];
vector<pair<int, pii> > vec;

int getdis(int i, int j){
	LL dx = x[i] - x[j],
		dy = y[i] - y[j];
	return dx * dx + dy * dy;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++)
			dis[j][i] = dis[i][j] = getdis(i, j), vec.PB(MP(dis[i][j], MP(i, j)));
	sort(all(vec), greater<pair<int, pii> >());
	cout.precision(15);
	for(int i = 0; i < sz(vec); i++){
		int u = vec[i].R.L,
			v = vec[i].R.R;
		adj[u][v] = adj[v][u] = true;
		if((adj[v] & adj[u]).count()){
			cout << fixed << sqrt(vec[i].L)/2 << '\n';
			return 0;
		}
	}
	return 0;
}