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
int tot[N],fa[N];
bool vis[N],Lock[N];
vi g[N];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void un(int x,int y){
	if(x==y)return;
	fa[x]=y;
	tot[y]+=tot[x];
	Lock[y]|=Lock[x];
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	rep(i,1,k+1){
		int t;
		scanf("%d",&t);
		while(t--){
			int id;
			scanf("%d",&id);
			g[id].pb(i);
		}
		fa[i]=i;fa[i+k]=i+k;
		tot[i]=1;tot[i+k]=0;
	}
	int ans=0;
	rep(i,1,n+1){
		if(g[i].size()==1){
			int x=g[i][0];
			int fx=find(x),fy=find(x+k);
			if(s[i]=='0'){
				Lock[fx]=1;
				if(!vis[fx]){
					ans+=tot[fx];
					if(vis[fy])ans-=tot[fy];
					vis[fx]=1;
					vis[fy]=0;
				}
			}
			else{
				Lock[fy]=1;
				if(!vis[fy]){
					ans+=tot[fy];
					if(vis[fx])ans-=tot[fx];
					vis[fy]=1;
					vis[fx]=0;
				}
			}
		}
		else if(g[i].size()==2){
			int x=g[i][0],y=g[i][1];
			int fx1=find(x),fx2=find(x+k),fy1=find(y),fy2=find(y+k);
			int ans1=ans,ans2;
			if(vis[fx1])ans1-=tot[fx1],vis[fx1]=0;
			if(vis[fx2])ans1-=tot[fx2],vis[fx2]=0;
			if(vis[fy1])ans1-=tot[fy1],vis[fy1]=0;
			if(vis[fy2])ans1-=tot[fy2],vis[fy2]=0;
			ans2=ans1;
			if(s[i]=='0'){
				un(fx1,fy2),un(fx2,fy1);
				
			} 
			else{
				un(fx1,fy1),un(fx2,fy2);
			}
			ans1+=tot[fy2],ans2+=tot[fy1];
			if(Lock[fy2]){
				ans=ans1;
				vis[fy2]=1;
			}
			else if(Lock[fy1]){
				ans=ans2;
				vis[fy1]=1;
			}
			else{
				if(ans1<ans2){
					ans=ans1;
					vis[fy2]=1;
				}
				else{
					ans=ans2;
					vis[fy1]=1;
				}
			}
		}
		printf("%d\n",ans);
	}
}