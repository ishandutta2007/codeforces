#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int n,a[100005],vis[100005],pw[100005],pn=1e5;
int main()
{
	pw[0]=1;
	for(int i=1;i<=pn;i++)
		pw[i]=2*pw[i-1]%mod;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=-1) vis[a[i]]++;
	}
	int ans=submod(pw[n-1]-1);
	for(int i=1;i<=n;i++)
		if(a[i]==-1)
			ans=submod(ans-submod(pw[vis[i]]-1));
	printf("%d",ans);
	return 0;
}