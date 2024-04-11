#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 1000000007
int n,maxb;
int a[MN],b[MN],p[MN],q[MN],f[MN],g[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d%d",a+i,b+i),p[i]=q[i]=i,maxb=max(maxb,b[i]);
	sort(p+1,p+n+1,[](int i,int j){return b[i]<b[j];});
	sort(q+1,q+n+1,[](int i,int j){return a[i]<a[j];});
	int j=0;
	int mn=0,gg=1;
	F(I,1,n){
		int i=p[I];
		while(j<n&&a[q[j+1]]<=b[i]){
			int u=q[++j];
			if(f[u]-a[u]<mn)mn=f[u]-a[u],gg=0;
			if(f[u]-a[u]==mn)gg=(gg+g[u])%mod;
		}
		f[i]=b[i]+mn;
		g[i]=gg;
	}
	mn=0x7fffffff,gg=0;
	F(i,1,n){
		if(a[i]<=maxb)continue;
		if(f[i]<mn)mn=f[i],gg=0;
		if(f[i]==mn)gg=(gg+g[i])%mod;
	}
	printf("%d\n",gg);
	return 0;
}