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
int ans[200010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	if(~n&1)return puts("NO"),0;
	puts("YES");
	for(int i=1;i<=n;++i)
		if(i&1)ans[i]=2*i,ans[i+n]=2*i-1;
		else ans[i]=2*i-1,ans[i+n]=2*i;
	for(int i=1;i<=n<<1;++i)printf("%d ",ans[i]);
	return 0;
}