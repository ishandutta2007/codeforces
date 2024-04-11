#include <bits/stdc++.h>
#define For(i,a,b)for(int i=a;i<=b;i++)
#define B(i)for(int i=head[u];i;i=nxt[i])
using namespace std;
typedef long long ll;
const ll inf=1000000000000ll;
#define N 200010
int n,cnt,head[N],v[N<<1],nxt[N<<1],To=0,s,e,T[N],H[N];
inline void add_edge(int s,int e){
	To++;v[To]=e;nxt[To]=head[s];head[s]=To;
	To++;v[To]=s;nxt[To]=head[e];head[e]=To;
}
ll f[N][2];
struct Data{
	ll a,b;
	Data(){a=b=0;}
	Data(ll _a,ll _b){a=_a;b=_b;}
    bool operator <(const Data &z)const{return b-a<z.b-z.a;}
}D[N];
inline ll calc(int u){
	ll res=inf,sum=0;
	sort(D+1,D+cnt+1);
	For(i,1,cnt)sum+=D[i].a;
	res=min(res,sum+1ll*cnt*T[u]);
	For(i,1,cnt)sum+=D[i].b-D[i].a,res=min(res,sum+1ll*max(i,cnt-i)*T[u]);
	return res;
}
void dfs(int u,int fa){
	B(i)if(v[i]^fa)dfs(v[i],u);
    cnt=0;
    B(i)if(v[i]^fa)cnt++,H[u]<=H[v[i]]?D[cnt].a=f[v[i]][1]:D[cnt].a=inf,H[u]>=H[v[i]]?D[cnt].b=f[v[i]][0]:D[cnt].b=inf;
	D[++cnt]=Data(0,inf);
	f[u][0]=calc(u);
	cnt=0;
	B(i)if(v[i]^fa)cnt++,H[u]<=H[v[i]]?D[cnt].a=f[v[i]][1]:D[cnt].a=inf,H[u]>=H[v[i]]?D[cnt].b=f[v[i]][0]:D[cnt].b=inf;
	D[++cnt]=Data(inf,0);
	f[u][1]=calc(u);
	if(u==1){
		cnt=0;
	    B(i)if(v[i]^fa)cnt++,H[u]<=H[v[i]]?D[cnt].a=f[v[i]][1]:D[cnt].a=inf,H[u]>=H[v[i]]?D[cnt].b=f[v[i]][0]:D[cnt].b=inf;
		f[u][0]=calc(u);
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&T[i]);
	}
	For(i,1,n){
		scanf("%d",&H[i]);
	}
	For(i,1,n-1){
		scanf("%d%d",&s,&e);
		add_edge(s,e);
	}
	dfs(1,0);
	printf("%lld\n",min(f[1][0],f[1][1]));
	return 0;
}