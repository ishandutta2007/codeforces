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
int fir[100010],dis[200010],nxt[200010],id;
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
std::vector<int>G[100010];
int tot,mid,d;
il int dfs(int x){
	int mx=0,cmx=0;
	for(int i=0;i<G[x].size();++i){
		d=dfs(G[x][i]);
		if(d>mx)cmx=mx,mx=d;
		else if(d>cmx)cmx=d;
	}
	if(mx+cmx+1>=mid)++tot,mx=-1;
	return mx+1;
}
il vd DFS(int x,int fa=-1){
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i])continue;
		G[x].push_back(dis[i]);
		DFS(dis[i],x);
	}
}
int R[100010];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b,blk=sqrt(n*log2(n)),lim=n/blk,l,r;
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	DFS(1);
	for(int i=1;i<=blk;++i)mid=i,tot=0,dfs(1),printf("%d\n",tot);
	for(int i=0;i<=lim;++i){
		l=0,r=n;
		while(l<r){
			mid=((l+r)>>1)+1;tot=0;dfs(1);
			if(tot>=i)l=mid;
			else r=mid-1;
		}
		R[i]=l;
	}
	int p=lim;
	for(int i=blk+1;i<=n;++i){
		while(R[p]<i)--p;
		printf("%d\n",p);
	}
	return 0;
}