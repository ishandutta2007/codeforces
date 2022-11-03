#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
const int B=108,C=200000/B;
char S[200010];
int s[200010],a[200010],p[200010],m;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",S+1);int n=strlen(S+1);ll ans=0;
	for(int i=1;i<=n;++i)s[i]=(S[i]=='1')+s[i-1];
	// cnt_1 * k = r-l+1
	// 1. k <= B
	for(int k=1;k<=B;++k){
		for(int j=0;j<=n;++j)a[j]=j-s[j]*k;
		std::sort(a,a+n+1);
		for(int l=0,r;l<=n;l=r+1){
			r=l;while(r<n&&a[r+1]==a[r])++r;
			ans+=1ll*(r-l+1)*(r-l)/2;
		}
	}
	// 2. cnt_1 <= B,k>B
	p[0]=n+1;
	for(int i=n,l,r;i;--i){
		if(S[i]=='1')p[++m]=i;
		for(int j=m;j&&m-j<C;--j){
			l=std::max((m-j+1)*B+1,p[j]-i+1),r=p[j-1]-i+1;
			if(l<=r)ans+=(r-1)/(m-j+1)-(l-1)/(m-j+1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}