#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 9;
vector<int> T[N];
char let[N];

vector<pii> D[N];

int subt[N];
int op[N];
int tt;

int d[N];


int x1, x2;
void dfs(int u){
	op[u] = ++ tt;
	subt[u] = 1;
	if(D[d[u]].empty())
		x1 = 0;
	else
		x1 = D[d[u]].back().se;
	x2 = 1 << (let[u] - 'a');
	x2 ^= x1;
	D[d[u]].push_back(mp(op[u], x2));
	for(auto x : T[u]){
		d[x] = d[u] + 1;
		dfs(x);
		subt[u] += subt[x];
	}
}


int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	int p;
	for(int i = 2; i <= n; i ++ ){
		cin >> p;
		T[p].push_back(i);
	}
	for(int i = 1; i <= n; i ++ ){
		cin >> let[i];
	}
	d[1] = 1;
	dfs(1);
	int v, h;
	int l, r;
	int vl;
	for(int i = 0 ; i < m ; i ++ ){
		cin >> v >> h;
		l = lower_bound(D[h].begin(), D[h].end(), mp(op[v], -1)) - D[h].begin();
		r = lower_bound(D[h].begin(), D[h].end(), mp(op[v] + subt[v], -1)) - D[h].begin();
		-- r;
		if(r < 0){
			cout << "Yes" << "\n";
		}
		else{
			vl = D[h][r].se;
			if(l != 0)
				vl ^= D[h][l - 1].se;
			if(__builtin_popcount(vl) <= 1){
				cout << "Yes\n";
			}
			else{
				cout << "No\n";
			}
		}
	}
	return 0;
}