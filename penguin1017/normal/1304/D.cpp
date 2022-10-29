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
char s[N];
int ans[N],pos[N],vis[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		rep(i,1,n+1)vis[i]=0;
		int cnt=0;
		per(i,1,n)if(s[i]=='>')ans[i+1]=++cnt,vis[i+1]=1;
		per(i,1,n+1){
			if(!vis[i]){
				int pos=i;
				for(pos;pos;--pos)if(vis[pos])break;
				++pos;
				rep(j,pos,i+1)ans[j]=++cnt;
				i=pos;
			}
		} 
		rep(i,1,n+1)printf("%d ",ans[i]);
		printf("\n");
		rep(i,1,n+1)vis[i]=0;
		cnt=0;
		rep(i,1,n)if(s[i]=='<')ans[i]=++cnt,vis[i]=1;
		per(i,1,n+1)if(!vis[i])ans[i]=++cnt;
		rep(i,1,n+1)printf("%d ",ans[i]);
		printf("\n");
	}
}