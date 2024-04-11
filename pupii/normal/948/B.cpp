// It is made by XZZ
#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#define int long long
#define il inline
#define rg register
#define vd void
#define sta static
using namespace std;
typedef long long ll;
il int gi(){
    rg int x=0,f=1;rg char ch=getchar();
    while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int x2,x1[1000001],tot,flg[1000001],f[1000001];
main(){
	x2=gi();
	for(int i=2;i<1000001;++i)
		if(!flg[i])
			for(int j=i*2;j<1000001;j+=i){
				flg[j]=1;
				f[j]=max(f[j],i);
			}
	int ans=1<<30;
	for(int i=x2-f[x2]+1;i<=x2;++i)
		if(flg[i])ans=min(ans,i-f[i]+1);
	printf("%lld\n",ans);
    return 0;
}