// It is made by XZZ
#include<cstdio>
#include<algorithm>
#define il inline
#define rg register
#define vd void
#define sta static
#define int long long
il int gi(){
	rg int x=0,f=1;rg char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
main(){
	#ifdef xzz
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	#endif
	int n=gi(),q=gi(),x;
	while(q--){
		x=gi();
		int ans=0,_n=n;
		while((x&1)==0){
			x>>=1;
			if(_n&1){--x;if(x==0)x=_n>>1;}
			ans+=(_n>>1)+(_n&1);_n>>=1;
		}
		printf("%lld\n",ans+(x>>1)+1);
	}
	return 0;
}