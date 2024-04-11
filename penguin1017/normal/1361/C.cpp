#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
const ll Inf=1e18;
int a[N],b[N];
int e[N],head[N],nxt[N],ve[N],vis[N],fa[N],tot,cnt;
int stk[N],tp;
void add(int u,int v){
	nxt[tot]=head[u],head[u]=tot,e[tot++]=v;
	nxt[tot]=head[v],head[v]=tot,e[tot++]=u;
}
int dsu(int x){
	if(fa[x]==x)return x;
	return fa[x]=dsu(fa[x]);
}
void con(int u,int v){
	u=dsu(u),v=dsu(v);
	if(u^v)fa[u]=v;
}
void eul(int u){
	for(int &i=head[u];~i;i=nxt[i]){
		if(ve[i])continue;
		ve[i]=ve[i^1]=1;
		int id=i;
		eul(e[i]);
		printf("%d %d ",(id^1)+1,(id)+1);
		cnt+=2;
	}
}
int main(){
	memset(head,-1,sizeof head);
	int n,ans=20;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d%d",&a[i],&b[i]);
		ans=min(ans,__builtin_ctz(lb(a[i]^b[i])));
	}
	if(n==1){
		printf("%d\n",ans);
		printf("1 2");
		return 0;
	}
	per(i,0,21){
		int m=(1<<i)-1;
		rep(j,0,m+1)vis[j]=0,fa[j]=j;
		rep(j,0,n){
			int u=a[j]&m,v=b[j]&m;
			vis[u]++,vis[v]++;
			con(u,v); 
		}
		int ok=1,p;
		rep(j,0,m+1){
			if(vis[j]){
				p=dsu(j);
				break;
			}
		}
		rep(j,0,m+1){
			if(vis[j]&1){
				ok=0;
				break;
			}
			if(vis[j]&&dsu(j)!=p){
				ok=0;
				break;
			}
		}
		if(ok){
			printf("%d\n",i);
			rep(j,0,n){
				int u=a[j]&m,v=b[j]&m;
				add(u,v);
			}
			eul(a[0]&m); 
			return 0;
		}
	}
	printf("%d\n",ans);
	rep(i,1,2*n+1)printf("%d ",i);
}