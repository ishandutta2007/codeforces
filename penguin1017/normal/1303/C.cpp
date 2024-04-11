#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
int e[26][26],deg[26],cnt,vis[26];
char s[210],ans[30];
vi g[26];
void dfs(int u,int f){
//	cout<<u<<"u\n";
	ans[cnt++]=u;
	vis[u]=1;
	for(auto v:g[u]){
		if(v==f)continue;
	//	cout<<u<<' '<<v<<"uu\n";
		dfs(v,u);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(e,0,sizeof e);
		memset(deg,0,sizeof deg);
		memset(vis,0,sizeof vis);
		rep(i,0,26)g[i].clear();
		scanf("%s",s);
		int n=strlen(s);
		if(n==1){
			rep(i,0,26)ans[i]=i+'a';
			printf("YES\n%s\n",ans);
			continue;
		}
		rep(i,1,n){
			e[s[i-1]-'a'][s[i]-'a']=1;
			e[s[i]-'a'][s[i-1]-'a']=1;
		}
		rep(i,0,26)rep(j,0,26)if(e[i][j]==1)deg[i]++,g[i].pb(j);
		int flag=0;
		rep(i,0,26)if(deg[i]>2)flag=1;
		if(flag){
			printf("NO\n");
			continue;
		}
		flag=1;
		int pos;
		rep(i,0,26)if(deg[i]==1)pos=i,flag=0;
		if(flag){
			printf("NO\n");
			continue;
		}
		cnt=0;
		dfs(pos,-1);
		rep(i,0,26)if(!vis[i])ans[cnt++]=i;
		rep(i,0,26)ans[i]+='a';
		printf("YES\n%s\n",ans);
	}
}