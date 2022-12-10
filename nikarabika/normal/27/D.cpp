#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MP make_pair
#define PB push_back
#define L first
#define R second

const int maxn = 110;
pii a[maxn];
bool mark[maxn], part[maxn];
vector<int> adj[maxn];
int n, m;

void dfs(int v, bool ty){
	mark[v] = true;
	part[v] = ty;
	for(auto u : adj[v]){
		if(!mark[u])
			dfs(u, !ty);
		else if(ty == part[u]){
			cout << "Impossible\n";
			exit(0);
		}
	}
	return;
}

bool overlap(int id1, int id2){
	if(a[id1].L == a[id2].L or a[id1].L == a[id2].R or a[id1].R == a[id2].L or a[id1].R == a[id2].R)
		return false;
	if(a[id1].L > a[id2].L)
		swap(id1, id2);
	if(a[id1].R < a[id2].L)
		return false;
	return a[id1].R < a[id2].R;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a[i].L >> a[i].R;
		if(a[i].L > a[i].R)
			swap(a[i].L, a[i].R);
		for(int j = 0; j < i; j++)
			if(overlap(i, j))
				adj[i].PB(j), adj[j].PB(i);
	}
	for(int i = 0; i < m; i++)
		if(!mark[i])
			dfs(i, 0);
	for(int i = 0; i < m; i++)
		cout << ((part[i]) ? 'i' : 'o');
	return 0;
}