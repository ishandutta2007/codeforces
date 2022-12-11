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
const int LOG = 18;
vector<pii> T[N];
int docm[N];
int rec_time[N];

int ti[N];
bool is_par[N];
int up[LOG][N];
int mxq[LOG][N];

int subt[N];
int open_t[N];
int pp = 1;

void dfs(int u, int par, int last_edge){
	up[0][u] = par;
	mxq[0][u] = last_edge;
	for(int j = 1; j < LOG; j ++ ){
		up[j][u] = up[j - 1][up[j - 1][u]];
		mxq[j][u] = max(mxq[j - 1][u], mxq[j - 1][up[j - 1][u]]);
	}
	subt[u] = 1;
	open_t[u] = pp ++ ;
	for(auto x : T[u]){
		dfs(x.fi, u, x.se);
		subt[u] += subt[x.fi];
	}
}

bool is_ancestor(int u, int v){ // if u is higher in v
	int tl = open_t[u];
	int tr = tl + subt[u] - 1;
	if(open_t[v] >= tl and open_t[v] <= tr){
		return true;
	}
	return false;
}

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	int typ[m];
	int x[m];
	int y[m];
	for(int i = 0 ; i < m ; i ++ ){
		cin >> typ[i];
		if(typ[i] == 1){
			cin >> x[i] >> y[i];
			is_par[x[i]] = true;
			T[y[i]].push_back(mp(x[i], i));
		}
		else if(typ[i] == 2){
			cin >> x[i];
		}
		else{
			cin >> x[i] >> y[i];
		}
	}
	for(int i = 1; i <= n; i ++ )
		if(is_par[i] == false)
			dfs(i, i, 0);
	int node;
	int doc = 0;
	int s_time, s_node;
	bool ok;
	for(int i = 0; i < m; i ++ ){
		if(typ[i] == 1){
			continue;
		}
		else if(typ[i] == 2){
			++ doc;
			docm[doc] = x[i];
			rec_time[doc] = i;
		}
		else{
			node = x[i];
			ok = false;
			s_time = rec_time[y[i]];
			s_node = docm[y[i]];
			for(int j = LOG - 1; j >= 0 ; j -- ){
				if(mxq[j][s_node] < s_time){
					
					if(!is_ancestor(up[j][s_node], node)){
						s_node = up[j][s_node];
					}
				}
			}
			if((up[0][s_node] == node and mxq[0][s_node] < s_time) or s_node == node){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}
	return 0;
}