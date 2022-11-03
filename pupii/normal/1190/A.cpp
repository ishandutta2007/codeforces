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
ll p[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	ll n=gi(),m=gi(),k=gi();
	for(int i=1;i<=m;++i)p[i]=gi();
	int ans=0,del=0;
	for(int l=1,r;l<=m;l=r+1){
		ll nowpage=(p[l]-del+k-1)/k,R=nowpage*k;
		r=l;while(r!=m&&p[r+1]-del<=R)++r;
		del+=r-l+1;
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}