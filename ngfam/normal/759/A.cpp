#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int done[N];
int fix[N][2];
int a[N], b[N];

void dfs(int u){
	if(done[u] == 1) return;
	done[u] = 1;
	dfs(a[u]);
}

void visit(int u, int p){
	if(fix[u][p]) return;
	fix[u][p] = 1;	
	visit(a[u], b[u] ? 1 - p : p);
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);

	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	int ans = 0, sum = 0;

	for(int i = 1; i <= n; ++i){
		scanf("%d", b + i);
		sum += b[i];
	}

	ans = 1 - sum % 2;

	int comp = 0;
	for(int i = 1; i <= n; ++i){
		if(!done[i]){
			++comp;
			dfs(i);
		}
	}

	if(comp == 1) comp = 0;

	cout << ans + comp;

	return 0;
}