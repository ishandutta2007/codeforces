#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,fir[1010],dis[4010],nxt[4010],id=1,A,B,W[4010];
il vd link(int a,int b){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a;
}
int f[1010],siz[1010],rt;
il vd getrt(int x){
	siz[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(siz[dis[i]])continue;
		getrt(dis[i]);
		f[x]=std::max(f[x],siz[dis[i]]);
		siz[x]+=siz[dis[i]];
	}
	f[x]=std::max(f[x],n-siz[x]);
	if(f[rt]>f[x])rt=x;
}
il vd dfs(int x,int fa=-1){
	siz[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i])continue;
		dfs(dis[i],x);
		siz[x]+=siz[dis[i]];
	}
}
int NUM[1010],FA[1010],SIZ[1010];
std::priority_queue<std::pair<int,int>>que;
il int HD(int x){return FA[x]==x?x:FA[x]=HD(FA[x]);}
il vd DFS(int x,int mul,int fa=-1){
	int o=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i]||rt==dis[i])continue;
		W[i]=W[i^1]=o*mul;
		DFS(dis[i],mul,x);
		o+=siz[dis[i]];
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();int a,b;
	if(n==1)return 0;
	if(n==2)return puts("1 2 1"),0;
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,b);
	f[0]=1e9;getrt(1);
	dfs(rt);int m=0;
	for(int i=fir[rt];i;i=nxt[i])NUM[++m]=dis[i],FA[m]=m,SIZ[m]=siz[dis[i]],que.push({-SIZ[m],m});
	int x,y;
	while(que.size()>1){
		x=HD(que.top().second);que.pop();
		y=HD(que.top().second);que.pop();
		if(SIZ[x]+SIZ[y]<=n/2)FA[x]=y,SIZ[y]+=SIZ[x],que.push({-SIZ[y],y});
		else{que.push({-SIZ[x],x}),que.push({-SIZ[y],y});break;}
	}
	if(que.size()>2){
		assert(que.size()==3);
		x=HD(que.top().second);que.pop();
		y=HD(que.top().second);que.pop();
		FA[x]=y,SIZ[y]+=SIZ[x],que.push({-SIZ[y],y});
	}else assert(que.size()==2);
	x=HD(que.top().second);que.pop();
	y=HD(que.top().second);que.pop();
	A=n+1,B=n+2;
	for(int i=1;i<=m;++i)link(HD(i)==x?A:B,NUM[i]);
	DFS(A,1);DFS(B,SIZ[x]+1);
	for(int i=2;i<=id;i+=2){
		int a=dis[i],b=dis[i^1],c=W[i];
		if(a==rt||b==rt)continue;
		a=(a==A||a==B)?rt:a;b=(b==A||b==B)?rt:b;
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}