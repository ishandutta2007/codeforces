#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,d,a[200069],as[200069];

int main()
{
	long long t,rr,i,k,l,c,p;
	pair<long long,long long> mne;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			as[i]=a[i];
		}
		sort(as+1,as+n+1);
		k=(n+d+1)/2;
		mne.fr=inf;
		for(i=k;i<=n;i++)
		{
			mne=min(mne,{as[i]-as[i-k+1],as[i-k+1]});
		}
		k=mne.sc;
		l=mne.sc+mne.fr;
		printf("%lld %lld\n",k,l);
		c=0;
		p=0;
		for(i=1;i<=n;i++)
		{
			c+=(a[i]>=k&&a[i]<=l)*2-1;
			if(d>1&&c>0||i==n)
			{
				printf("%lld %lld\n",p+1,i);
				d--;
				c=0;
				p=i;
			}
		}
	}
}