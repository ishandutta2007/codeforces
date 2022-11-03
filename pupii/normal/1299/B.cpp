#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
int px[100010],py[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)px[i]=gi(),py[i]=gi();
	px[0]=px[n],py[0]=py[n];
	if(n&1)return puts("NO"),0;
	for(int i=1,j=n/2+1;j<=n;++i,++j){
		if(px[i]-px[i-1]!=px[j-1]-px[j])return puts("NO"),0;
		if(py[i]-py[i-1]!=py[j-1]-py[j])return puts("NO"),0;
	}puts("YES");
	return 0;
}