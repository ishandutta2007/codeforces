#include <cstdio>
#include <vector>
using namespace std;
const int maxn=312345;
int n, m, dp[maxn], vis[maxn];
char s[maxn];
vector<int> G[maxn], T;
bool cyclic(int u){
	if(vis[u]==2) return false;
	if(vis[u]==1) return true;
	vis[u]=1;
	for(int v:G[u])
		if(cyclic(v)) return true;
	vis[u]=2;
	T.push_back(u);
	return false;
}
int main(){
	scanf("%d%d", &n, &m);
	scanf("%s", s+1);
	for(int i=0; i<m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]&&cyclic(i)){
			puts("-1");
			return 0;
		}
	}
	int res=0;
	for(char ch='a'; ch<='z'; ch++){
		for(int u:T){
			int inc=(s[u]==ch);
			dp[u]=inc;
			for(int v:G[u])
				dp[u]=max(dp[u], dp[v]+inc);
			res=max(res, dp[u]);
		}
	}
	printf("%d\n", res);
	return 0;
}