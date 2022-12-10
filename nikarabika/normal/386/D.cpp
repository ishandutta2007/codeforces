#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;
typedef pair<int, pie> piie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 70 + 5;
vector<int> state_adj[maxn * maxn * maxn];
vector<int> adj[maxn][26];
int col[maxn][maxn];
int h[maxn * maxn * maxn], par[maxn * maxn * maxn];
bool mark[maxn * maxn * maxn];
queue<int> Q;
int n, a1, a2, a3;

int atob(piie x){
	if(x.L > x.R.L) swap(x.L, x.R.L);
	if(x.R.L > x.R.R) swap(x.R.L, x.R.R);
	if(x.L > x.R.L) swap(x.L, x.R.L);
	return x.L * maxn * maxn + x.R.L * maxn + x.R.R;
}

piie btoa(int x){
	return MP(x / (maxn * maxn), MP((x / maxn) % maxn, x % maxn));
}

void print_diff(piie x, piie y){
	int a[3] = {x.L, x.R.L, x.R.R};
	int b[3] = {y.L, y.R.L, y.R.R};
	for(int i = 0; i < 3; i++){
		bool found = false;
		for(int j = 0; j < 3; j++)
			if(a[i] == b[j])
				found = true;
		if(!found){
			cout << a[i] << ' ';
			break;
		}
	}
	for(int i = 0; i < 3; i++){
		bool found = false;
		for(int j = 0; j < 3; j++)
			if(b[i] == a[j])
				found = true;
		if(!found){
			cout << b[i] << '\n';
			break;
		}
	}
	return;
}

void make(int x){
	if(par[x] == 0)
		return;
	make(par[x]);
	print_diff(btoa(par[x]), btoa(x));
}

void bfs(int source){
	mark[source] = true;
	Q.push(source);
	while(Q.size()){
		int v = Q.front();
		Q.pop();
		for(auto u : state_adj[v]){
			if(!mark[u]){
				h[u] = h[v] + 1;
				mark[u] = true;
				par[u] = v;
				Q.push(u);
			}
		}
	}
}

int main(){
	cin >> n;
	cin >> a1 >> a2 >> a3;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			char c;
			cin >> c;
			if(c == '*')
				continue;
			adj[i][c - 'a'].PB(j);
			col[i][j] = c - 'a';
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			for(int k = j + 1; k <= n; k++){
				int state = atob(MP(i, MP(j, k)));
				for(auto x : adj[i][col[j][k]])
					if(x != j and x != k)
						state_adj[state].PB(atob(MP(x, MP(j, k))));
				for(auto x : adj[j][col[i][k]])
					if(x != i and x != k)
						state_adj[state].PB(atob(MP(i, MP(x, k))));
				for(auto x : adj[k][col[j][i]])
					if(x != j and x != i)
						state_adj[state].PB(atob(MP(i, MP(j, x))));
			}
		}
	}
	bfs(atob(MP(a1, MP(a2, a3))));
	if(!mark[atob(MP(1, MP(2, 3)))])
		cout << -1 << endl;
	else
		cout << h[atob(MP(1, MP(2, 3)))] << endl;
	make(atob(MP(1, MP(2, 3))));
	return 0;
}