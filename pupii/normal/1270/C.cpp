#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int T=gi();
	while(T--){
		int n=gi();ll a[4],b=0;
		ll SUM=0,XOR=0,x;
		while(n--)x=gi(),SUM+=x,XOR^=x;
		a[++b]=100000000000000000ll+(SUM&1);
		SUM+=a[b],XOR^=a[b];
		XOR*=2,a[++b]=(XOR-SUM)/2,a[++b]=(XOR-SUM)/2;
		printf("%lld\n",b);
		for(int i=1;i<=b;++i)printf("%lld ",a[i]);
		puts("");
	}
	return 0;
}