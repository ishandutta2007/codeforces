#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int n, m, lab[N], edge[N];

int fin(int u){
	if(lab[u] < 0) return u;
	return lab[u] = fin(lab[u]);
}                

void join(int u, int v){
	if(lab[u] > lab[v]) swap(u, v);
	lab[u] += lab[v];
	edge[u] += edge[v] + 1;
	lab[v] = u;
}

int main(){
 	#ifndef ONLINE_JUDGE
 		freopen("1.inp", "r", stdin);
 		freopen("1.out", "w", stdout);
 	#endif

 	memset(lab, -1, sizeof lab);

 	scanf("%d%d", &n, &m);
 	for(int i = 1; i <= m; ++i){
 	 	int u, v;
 	 	scanf("%d%d", &u, &v);
 //	 	join(fin(u), fin(v));
        	u = fin(u); v = fin(v);
        	if(u != v) join(u, v);
        	else{
        		++edge[u];
        	}
	}

 	int ans = 0;

 	for(int i = 1; i <= n; ++i){
 		if(lab[i] < 0){
 		//	cout << edge[i] << endl;
 			ans += (edge[i] == (-lab[i] - 1));
 		}
 	}

 	cout << ans;

 	return 0;
}