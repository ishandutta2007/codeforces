#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int n,m,ans,f[1000005],pn=100000;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int main()
{
	f[0]=f[1]=1;
	for(int i=2;i<=pn;i++)
		f[i]=addmod(f[i-1]+f[i-2]);
	scanf("%d%d",&n,&m);
	ans=addmod(2ll*submod(f[n]-1)%mod+2ll*submod(f[m]-1)%mod);
	printf("%d",addmod(ans+2));
	return 0;
}