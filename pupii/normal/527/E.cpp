#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fir[100010],dis[1000010],nxt[1000010],id=1,du[100010];
int dir[1000010];
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int P;
void dfs(int x,int fai=-1){
	for(int&i=fir[x];i;i=nxt[i])
		if(!dir[i]){
			dir[i]=dir[i^1]=-1;
			dfs(dis[i],i);
		}
	dir[fai]=1,dir[fai^1]=1;
	dir[fai^(P&1)]++;
	++P;
}
int A[1000010],B[1000010],o,in[100010],ou[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b;
	for(int i=1;i<=m;++i)a=gi(),b=gi(),link(a,b),link(b,a),++du[a],++du[b];
	std::vector<int>v;
	for(int i=1;i<=n;++i)if(du[i]&1)v.push_back(i);
	for(int i=0;i<v.size();i+=2)++m,a=v[i],b=v[i+1],link(a,b),link(b,a),++du[a],++du[b];
	dfs(1);
	for(int i=2;i<=id;i+=2)
		if(dir[i]==1)++ou[A[++o]=dis[i^1]],++in[B[o]=dis[i]];
		else++ou[A[++o]=dis[i]],++in[B[o]=dis[i^1]];
	for(int i=1;i<=n;++i)if(in[i]&1)A[++o]=i,B[o]=i;
	printf("%d\n",o);
	for(int i=1;i<=o;++i)printf("%d %d\n",A[i],B[i]);
	return 0;
}