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
int a[3510];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int t=gi();
	while(t--){
		int n=gi(),m=gi(),k=std::min(m-1,(int)gi());
		for(int i=1;i<=n;++i)a[i]=gi();
		int ans=0;
		for(int l=1,r=n-k;r<=n;++l,++r){
			int res=1e9;
			for(int i=0;i<=m-1-k;++i)
				res=std::min(res,std::max(a[l+i],a[r-(m-1-k-i)]));
			ans=std::max(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}