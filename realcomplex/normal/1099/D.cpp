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
vector<int> T[N];

ll answ = 0;

int s[N];

void dfs(int u, int mx){
	if(s[u] != -1){
		if(s[u] < mx){
			cout << "-1\n";
			exit(0);
		}
		mx = s[u];
	}
	for(auto x : T[u]){
		dfs(x, mx);
	}
}

int subt[N];

void dfs1(int u){
	subt[u] = (int)1e9 + 9;
	for(auto x : T[u]){
		dfs1(x);
		subt[u] = min(subt[u], subt[x]);
	}
	if(s[u] != -1)
		subt[u] = min(subt[u], s[u]); 
}

void dfs2(int u, int rem){
	if(subt[u] == (int)1e9 + 9)
		return;
	subt[u] -= rem;
	rem += subt[u];
	answ += subt[u];
	for(auto x : T[u]){
		dfs2(x, rem);
	}
}

int main(){
	fastIO;
	int n;
	cin >> n;
	int p;
	for(int i = 2; i <= n; i ++ ){
		cin >> p;
		T[p].push_back(i);
	}
	for(int i = 1; i <= n; i ++ )
		cin >> s[i];
	dfs(1, 0);
	dfs1(1);
	dfs2(1, 0);
	cout << answ;
	return 0;
}