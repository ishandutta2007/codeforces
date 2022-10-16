#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=312456;
vector<int> G[maxn];
int n, x, y, cnt[maxn];
int f=-1;
bool dfs(int u, int p){
	cnt[u]=1;
	bool flag=false;
	if(u==y) flag=true;
	for(int v:G[u]){
		if(v==p) continue;
		if(dfs(v, u)){
			flag=true;
			if(u==x) f=v;
		}
		cnt[u]+=cnt[v];
	}
	return flag;
}
int main(){
	scanf("%d%d%d", &n, &x, &y);
	for(int i=1; i<n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(x, -1);
	cout<<ll(n)*(n-1)-ll(cnt[x]-cnt[f])*cnt[y]<<endl;
	return 0;
}