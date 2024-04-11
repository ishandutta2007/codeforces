#include <bits/stdc++.h>

using namespace std;

long long n,m,a[169];
bitset<69> sq;

int main()
{
	long long t,rr,i,j,k,lh,rh,md,zz;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			cin>>s;
			a[i]=0;
			for(j=1;j<=m;j++)
			{
				a[i]=a[i]*2+s[j-1]-'0';
			}
		}
		sort(a+1,a+n+1);
		for(lh=0,rh=(1ll<<m)-1;lh<=rh;)
		{
			md=(lh+rh)/2;
			k=upper_bound(a+1,a+n+1,md)-a-1;
			if(md+1-k>=((1ll<<m)-n+1)/2)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		for(i=m;i;i--)
		{
			sq[i]=zz%2;
			zz/=2;
		}
		for(i=1;i<=m;i++)
		{
			printf("%lld",(long long)sq[i]);
		}
		printf("\n");
	}
}