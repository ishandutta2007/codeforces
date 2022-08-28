#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,n,k,pt,b[105];
ll a[100005],pw[105];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		pw[0]=1;
		pt=0;
		for(int i=1;;i++)
		{
			if(pw[i-1]*k>1.5e16) break;
			pw[i]=pw[i-1]*k;
			pt=i;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d",&a[i]);
		}
		for(int j=0;j<=pt;j++) b[j]=0;
		for(int i=1;i<=n;i++)
			for(int j=pt;j>=0;j--)
				while(a[i]>=pw[j])
				{
					a[i]-=pw[j];
					b[j]++;
				}
		int fl=1;
		for(int j=0;j<=pt;j++)
			if(b[j]>1) fl=0;
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}