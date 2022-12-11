#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
vector<int> T[N];
int tim[N];
bool ok[N];

int subt[N];

int n;

int ret;

int dfs(int node, int par){
	int nval;
	int mx1 = 0, mx2 = 0;
	subt[node] = 1;
	int alv = ok[node];
	for(auto x : T[node]){
		if(x == par)
			continue;
		nval = dfs(x, node);
		if(subt[x] == nval){
			alv += subt[x];
		}
		else{
			if(nval > mx1){
				mx2 = mx1;
				mx1 = nval;
			}
			else if(nval > mx2){
				mx2 = nval;
			}
		}
		subt[node] += subt[x];
	}
	if(!ok[node]){
		return 0;
	}
	else{
		ret = max(ret, mx1 + mx2 + alv);
		return alv + mx1;
	}
}

int best;

int Calc(int t){
	for(int i = 1; i <= n; i ++ ){
		ok[i] = (tim[i] >= t);
		subt[i] = 0;
	}
	ret = 0;
	dfs(best, -1);
	return ret;
}

int main(){
	fastIO;
	int k;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++ )
		cin >> tim[i];
	int u, v;
	for(int i = 0 ;i  < n - 1; i ++ ){
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	for(int i = 1; i <= n; i ++ ){
		if(best == 0 || tim[best] > tim[i])
			best = i;
	}
	int l = 0, r = (int)1e6 + 9;
	int md;
	while(l + 1 < r){
		md = (l + r) / 2;
		if(Calc(md) >= k){
			l = md;
		}
		else{
			r = md;
		}
	}
	cout << l << "\n";
	return 0;
}