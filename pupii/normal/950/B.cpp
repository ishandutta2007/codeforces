// It is made by XZZ
#include<cstdio>
#include<algorithm>
#define il inline
#define rg register
#define vd void
#define sta static
#define int long long
typedef long long ll;
il int gi(){
	rg int x=0,f=1;rg char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int x[1000001],y[100001];
main(){
	#ifdef xzz
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	#endif
	int n=gi(),m=gi();
	for(rg int i=1;i<=n;++i)x[i]=gi();
	for(rg int i=1;i<=m;++i)y[i]=gi();
	int a=0,b=0,Sa=0,Sb=0,ans=0;
	while(1){
		if(Sa==Sb&&Sa){
			Sa=Sb=0,++ans;
			if(a==n)break;
		}
		if(Sa<Sb)++a,Sa+=x[a];
		else ++b,Sb+=y[b];
	}
	printf("%lld\n",ans);
	return 0;
}