#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int t,n,fr[500005],infr[500005],pn=5e5;
char s[1000005];
int C(int x,int y)
{
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	infr[pn]=fpow(fr[pn],mod-2);
	for(int i=pn-1;i>0;i--)
		infr[i]=1ll*infr[i+1]*(i+1)%mod;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		int ct=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				if(i<n&&s[i+1]=='1')
				{
					ct++;
					i++;
				}
				else sum++;
			}
		}
		sum=n-2*ct-sum;
		printf("%d\n",C(sum+ct,sum));
	}
	return 0;
}