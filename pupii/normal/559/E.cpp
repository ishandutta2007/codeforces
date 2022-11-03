#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int L[110],R[110],p[110],u[310],f[110][310],pos[310];
int s[310];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b,m=0;
	for(int i=1;i<=n;++i)p[i]=a=gi(),b=gi(),L[i]=a-b,R[i]=a+b,u[++m]=L[i],u[++m]=R[i],u[++m]=p[i];
	std::sort(u+1,u+m+1);m=std::unique(u+1,u+m+1)-u-1;
	for(int i=1;i<=n;++i)L[i]=std::lower_bound(u+1,u+m+1,L[i])-u;
	for(int i=1;i<=n;++i)R[i]=std::lower_bound(u+1,u+m+1,R[i])-u;
	for(int i=1;i<=n;++i)pos[p[i]=std::lower_bound(u+1,u+m+1,p[i])-u]=i;
	for(int i=1;i<=n;++i)s[i]=i;
	std::sort(s+1,s+n+1,[&](int a,int b){return p[a]<p[b];});
	for(int _=1,i;_<=n;++_){
		i=s[_];
		for(int j=1;j<=m;++j)f[_][j]=std::max(f[_][j-1],f[_-1][j]);
		for(int j=L[i]+1;j<=p[i];++j)f[_][j]=std::max(f[_][j],f[_][j-1]+u[j]-u[j-1]);
		int MX=f[_-1][p[i]];
		for(int j=p[i]+1;j<=R[i];++j){
			f[_][j]=std::max(f[_][j],MX+u[j]-u[p[i]]);
			if(pos[j]&&L[pos[j]]<p[i])MX=std::max(MX,f[_-1][L[pos[j]]]+u[p[i]]-u[L[pos[j]]]);
		}
		for(int j=1;j<=m;++j)f[_][j]=std::max(f[_][j],f[_][j-1]);
	}
	printf("%d\n",f[n][m]);
	return 0;
}