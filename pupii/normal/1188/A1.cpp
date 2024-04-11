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
#ifdef mod
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
int d[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),u,v;
	for(int i=1;i<n;++i)u=gi(),v=gi(),++d[u],++d[v];
	int sum=0;
	for(int i=1;i<=n;++i)sum+=d[i]==2;
	if(sum&&n!=2)puts("NO");
	else puts("YES");
	return 0;
}