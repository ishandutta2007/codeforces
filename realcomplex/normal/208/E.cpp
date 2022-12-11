#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int LG = 18;

vector<int> T[N];

int in[N];
int out[N];
int tt;

int d[N];

vector<int> id[N];

int up[N][LG];

void dfs(int u, int par, int dep){
	if(dep >= 0)
		id[dep].push_back(tt);
	d[u] = dep;
	in[u] = tt;
	up[u][0] = par;
	for(int i = 1; i < LG; i ++ ) {
		if(up[u][i -  1] == -1)
			up[u][i] = -1;
		else
			up[u][i] = up[up[u][i - 1]][i - 1];
	}
	++ tt;
	for(auto x : T[u]){
		if(x != par)
			dfs(x, u, dep + 1);
	}
	out[u] = tt - 1;
}

int main(){
	fastIO;
	int n;
	cin >> n;
	int r[n];
	for(int i = 1 ; i <= n; i ++ ){
		cin >> r[i];
		T[r[i]].push_back(i);
	}
	dfs(0, -1, -1);
	int q;
	cin >> q;
	int vert;
	int upl;
	bool exists;
	int cl, cr;
	int req_dep;
	for(int i = 0 ; i < q; i ++ ){
		cin >> vert >> upl;
		exists = true;
		for(int j = 0 ; j < LG; j ++ ){
			if(upl & (1 << j)){
				if(up[vert][j] != -1){
					vert = up[vert][j];
				}
				else{
					exists = false;
					break;
				}
			}
		}
		if(vert == 0)
			exists = false;
		if(!exists){
			cout << 0 << " ";
			continue;
		}
		cl = in[vert];
		cr = out[vert];
		req_dep = d[vert] + upl;
		cl = lower_bound(id[req_dep].begin(), id[req_dep].end(), cl) - id[req_dep].begin();
		cr = upper_bound(id[req_dep].begin(), id[req_dep].end(), cr) - id[req_dep].begin();
		-- cr;
		cout << max(0, cr - cl) << " ";
	}
	return 0;
}