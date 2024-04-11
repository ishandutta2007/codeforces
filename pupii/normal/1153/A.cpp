#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define int long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	int n=gi(),t=gi();
	int ans1=1e18,ans2=0;
	for(int i=1;i<=n;++i){
		int s=gi(),d=gi();
		for(int i=15;~i;--i)if(s+(d<<i)<t)s+=d<<i;
		if(s<t)s+=d;
		if(ans1>s)ans1=s,ans2=i;
	}
	printf("%lld\n",ans2);
	return 0;
}