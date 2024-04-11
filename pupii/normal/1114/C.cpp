#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
#define int long long
il ll gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,b,ans=8e18;
il int solve(int k){
	int ret=0;
	for(int N=n;N;N/=k)ret+=N/k;
	return ret;
}
main(){
	n=gi(),b=gi();
	int pr,e;
	for(ll i=2;i*i<=b;++i)
		if(b%i==0){
			pr=i;e=0;
			while(b%i==0)e++,b/=i;
			ans=std::min(ans,solve(pr)/e);
		}
	if(b!=1)pr=b,e=1,ans=std::min(ans,solve(pr)/e);;
	printf("%lld\n",ans);
	return 0;
}