#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;
int n,x,y;
int h[51],to[101],ne[101],sz[51];
long double c[51][51],fac[51];
long double f[51][51],g[51],tp[51];
inline void link(int x,int y,int k){
	to[k]=y;
	ne[k]=h[x];
	h[x]=k;
}
inline void dfs(int i,int fa){
	sz[i]=0,f[i][0]=1;
	for(int k=h[i];k;k=ne[k]){
		if(to[k]==fa) continue;
		dfs(to[k],i);
		memset(g,0,sizeof(g));
		sz[to[k]]++;
		for(int l1=1;l1<=sz[to[k]];l1++) g[l1]=g[l1-1]+f[to[k]][l1-1]/2;
		for(int l1=0;l1<=sz[to[k]];l1++) g[l1]+=f[to[k]][l1]*(sz[to[k]]-l1);
		memset(tp,0,sizeof(tp));
		for(int l1=0;l1<=sz[i];l1++)
			for(int l2=0;l2<=sz[to[k]];l2++)
				tp[l1+l2]+=f[i][l1]*g[l2]*c[l1+l2][l1]*c[sz[i]-l1+sz[to[k]]-l2][sz[i]-l1];
		memcpy(f[i],tp,sizeof(tp));
		sz[i]+=sz[to[k]];
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		link(x,y,(i<<1)-1);
		link(y,x,i<<1);
	}
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i;
	c[0][0]=1;
	for(int i=1;i<=n;i++){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	for(int i=1;i<=n;i++){
		dfs(i,0);
		cout<<fixed<<setprecision(9)<<f[i][n-1]/fac[n-1]<<endl;
	}
}