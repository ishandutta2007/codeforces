#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fir[300010],dis[600010],nxt[600010],intree[600010],id=1;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int mx[300010],mn[300010],cir,stk[300010],ins[300010],tp,vis[300010];
void dfs(int x){
	stk[ins[x]=++tp]=x;vis[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(intree[i])continue;
		if(!vis[dis[i]])intree[i]=intree[i^1]=1,dfs(dis[i]);
		else if(ins[dis[i]]){
			++cir;mn[cir]=1e9;
			for(int j=ins[dis[i]];j<=ins[x];++j)mn[cir]=std::min(mn[cir],stk[j]),mx[cir]=std::max(mx[cir],stk[j]);
		}
	}
	ins[x]=0;--tp;
}
int Right[300010];ll sR[300010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b;
	for(int i=1;i<=m;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	for(int i=1;i<=n;++i)if(!vis[i])dfs(i);
	for(int i=1;i<=n+1;++i)Right[i]=n;
	for(int i=1;i<=cir;++i)Right[mn[i]]=std::min(Right[mn[i]],mx[i]-1);
	for(int i=n;i;--i)Right[i]=std::min(Right[i],Right[i+1]);
	for(int i=1;i<=n;++i)sR[i]=sR[i-1]+Right[i];
	int q=gi(),L,R,l,r,mid;
	while(q--){
		L=gi(),R=gi();
		l=L,r=R+1;
		while(l<r){
			mid=(l+r)>>1;
			if(Right[mid]>=R)r=mid;
			else l=mid+1;
		}
		printf("%lld\n",sR[l-1]-sR[L-1]-1ll*(L+l-3)*(l-L)/2+1ll*(R-l+1)*(R-l+2)/2);
	}
	return 0;
}