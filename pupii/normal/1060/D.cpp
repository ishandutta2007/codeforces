#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int a[100100],b[100100];
main(){
#ifndef ONLINE_JUDGE
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n=gi(),ans=n;
	for(int i=1;i<=n;++i)a[i]=gi(),b[i]=gi();
	std::sort(a+1,a+n+1);std::sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)ans+=std::max(a[i],b[i]);
	printf("%lld\n",ans);
	return 0;
}