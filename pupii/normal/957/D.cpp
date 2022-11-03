// It is made by XZZ
#include<bits/stdc++.h>
#define int long long
#define il inline
#define rg register
#define vd void
#define sta static
typedef long long ll;
using namespace std;
il int gi(){
    rg int x=0,f=1;rg char ch=getchar();
    while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[100011],h[100011];
main(){
	int n=gi();
	for(rg int i=1;i<=n;++i)a[i]=gi();
	for(rg int i=n;i;--i)h[i]=max(a[i],h[i+1]-1);
	for(rg int i=2;i<=n;++i)h[i]=max(h[i],h[i-1]);
	int ans=0;
	for(rg int i=1;i<=n;++i)ans+=h[i]-a[i];
	printf("%lld\n",ans);
    return 0;
}