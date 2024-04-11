// It is made by XZZ
#include<cstdio>
#include<algorithm>
#define il inline
#define rg register
#define vd void
#define sta static
#define int long long
using namespace std;
il int gi(){
	rg int x=0,f=1;rg char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,a[100001];
char b[100001];
int ll=-1e9-1,rr=1e9+1;
main(){
#ifdef xzz
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	n=gi();
	for(rg int i=1;i<=n;++i)a[i]=gi();
	scanf("%s",b+1);
	for(rg int i=1;i<=n;++i){
		if(b[i]=='0'&&b[i-1]=='1'&&b[i-2]=='1'&&b[i-3]=='1'&&b[i-4]=='1')rr=min(rr,min(min(min(a[i-4],a[i-1]),min(a[i-2],a[i-3])),a[i]));
		else if(b[i]=='1'&&b[i-1]=='0'&&b[i-2]=='0'&&b[i-3]=='0'&&b[i-4]=='0')ll=max(ll,max(max(max(a[i-4],a[i-1]),max(a[i-2],a[i-3])),a[i]));
	}
	printf("%lld %lld\n",ll+1,rr-1);
	return 0;
}