#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
ll T;
int tot[100010],t[100010],ut[100010],u;
int fir[100010],dis[100010],nxt[100010],w[100010],id;
il vd link(int a,int b,int c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
int rt[100010],ls[10000010],rs[10000010],sum[10000010];ll Sum[10000010],cnt;
int f[100010];
#define mid ((l+r)>>1)
il vd update(int&x,int l,int r,const int&p,const int&d){
	++cnt,ls[cnt]=ls[x],rs[cnt]=rs[x],sum[cnt]=sum[x],Sum[cnt]=Sum[x];x=cnt;
	if(l==r){Sum[x]+=1ll*ut[l]*d,sum[x]+=d;return;}
	if(p<=mid)update(ls[x],l,mid,p,d);
	else update(rs[x],mid+1,r,p,d);
	sum[x]=sum[ls[x]]+sum[rs[x]];
	Sum[x]=Sum[ls[x]]+Sum[rs[x]];
}
il vd Update(int&x,int l,int r,const ll&d){
	++cnt,ls[cnt]=ls[x],rs[cnt]=rs[x],sum[cnt]=sum[x],Sum[cnt]=Sum[x];x=cnt;
	if(l==r){sum[x]=std::min((ll)sum[x],d/ut[l]),Sum[x]=std::min(Sum[x],d/ut[l]*ut[l]);return;}
	if(d<=Sum[ls[x]])rs[x]=0,Update(ls[x],l,mid,d);
	else Update(rs[x],mid+1,r,d-Sum[ls[x]]);
	sum[x]=sum[ls[x]]+sum[rs[x]];
	Sum[x]=Sum[ls[x]]+Sum[rs[x]];
}
#undef mid
il vd DFS(int x,ll LEN=0){
	if(LEN>T)return;
	update(rt[x],1,u,t[x],tot[x]);
	Update(rt[x],1,u,T-2*LEN);
	f[x]=sum[rt[x]];
	int mx=0,cmx=0;
	for(int i=fir[x];i;i=nxt[i]){
		rt[dis[i]]=rt[x];
		DFS(dis[i],LEN+w[i]);
		if(f[dis[i]]>mx)cmx=mx,mx=f[dis[i]];
		else if(f[dis[i]]>cmx)cmx=f[dis[i]];
	}
	f[x]=std::max(f[x],cmx);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();scanf("%lld",&T);
	for(int i=1;i<=n;++i)tot[i]=gi();
	for(int i=1;i<=n;++i)t[i]=ut[i]=gi();
	std::sort(ut+1,ut+n+1),u=std::unique(ut+1,ut+n+1)-ut-1;
	for(int i=1;i<=n;++i)t[i]=std::lower_bound(ut+1,ut+u+1,t[i])-ut;
	int fa,len;
	for(int i=2;i<=n;++i)fa=gi(),len=gi(),link(fa,i,len);
	DFS(1);
	int ans=f[1];
	for(int i=fir[1];i;i=nxt[i])ans=std::max(ans,f[dis[i]]);
	printf("%d\n",ans);
	//for(int i=1;i<=n;++i)printf("%d %d\n",i,sum[rt[i]]);
	return 0;
}