#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = 505;

vector<int> T[N];
int vis[N];
int p[N];

vector<int> cycle;
bool ok;


void dfs1(int u, int ls){
	if(!ok or vis[u] == 2)
		return;
	if(vis[u] == 1){
		cycle.push_back(u);
		int lp = ls;
		while(lp != u){
			cycle.push_back(lp);
			lp = p[lp];
		}
		cycle.push_back(u);
		ok = false;
		return;
	}
	vis[u] = 1;
	p[u] = ls;
	for(auto x : T[u]){
		dfs1(x, u);
	}
	vis[u] = 2;
}

int bu, bv;

bool dfs2(int u){
	if(vis[u] == 2)
		return false;
	if(vis[u] == 1)
		return true;
	vis[u] = 1;
	for(auto x : T[u]){
		if(u != bu or x != bv){
			if(dfs2(x))
				return true;
		}
	}
	vis[u] = 2;
	return false;
}

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	ok = true;
	int u, v;
	for(int i = 0; i < m; i ++ ){
		cin >> u >> v;
		T[u].push_back(v);
	}
	for(int i = 1; i <= n; i ++ ){
		dfs1(i, -1);
	}
	if(ok){
		cout << "YES\n";
		return 0;
	}
	bool good;
	for(int i = 1; i < cycle.size() ; i ++ ){
		bu = cycle[i];
		bv = cycle[i - 1];
		for(int j = 1;j <= n;j ++ ){
			vis[j] = 0;
		}
		good = true;
		for(int j = 1;j <= n;j ++ ){
			if(dfs2(j)){
				good = false;
			}
		}
		if(good){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}