#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=300007, maxm=600007;
int ecnt, head[maxn], to[maxm], Next[maxn];
void add(int u, int v){
	to[++ecnt]=v;
	Next[ecnt]=head[u];
	head[u]=ecnt;
	return ;
}
int n, m;
int vis[maxn], cnt[maxn];
char id[maxn];
bool flag;
void chk(int u){
	vis[u]=-1;
	for(int i=head[u]; i; i=Next[i]){
		if(flag){
			return ;
		}
		int v=to[i];
		if(vis[v]==0){
			chk(v);
		}
		if(vis[v]==-1){
			flag=1;
			return ;
		}
	}
	vis[u]=1;
	return ;
}
int dp[maxn][27];
int main(){
	scanf("%d%d", &n, &m);
	scanf("%s", id+1);
	for(int i=1; i<=m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		cnt[v]++;
	}
	for(int i=1; i<=n; i++){
		if(vis[i]==0){
			chk(i);
			if(flag){
				printf("-1");
				return 0;
			}
		}
	}
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(cnt[i]==0){
			dp[i][id[i]-'a']=1;
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u]; i; i=Next[i]){
			int v=to[i];
			for(int j=0; j<26; j++){
				dp[v][j]=max(dp[v][j], dp[u][j]+(id[v]==j+'a'? 1:0));
			}
			cnt[v]--;
			if(cnt[v]==0){
				q.push(v);
			}
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<26; j++){
			ans=max(ans, dp[i][j]);
		}
	}
	printf("%d", ans);
	return 0;
}