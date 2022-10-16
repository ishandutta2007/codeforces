#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069],zs=0;
bitset<200069> sq;

int main()
{
	long long i,ii,p[2],mx,e,ls=-1e18,u;
	pair<long long,long long> mne,mxe={-1e18,-1};
	bool bad=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	p[0]=1;
	p[1]=n;
	for(;1;)
	{
		mne={1e18,-1};
		for(ii=0;ii<2;ii++)
		{
			if(a[p[ii]]>ls)
			{
				mne=min(mne,{a[p[ii]],ii});
			}
		}
		e=mne.sc;
		if(e==-1)
		{
			bad=1;
			break;
		}
		if(a[p[0]]==a[p[1]])
		{
			break;
		}
		ls=a[p[e]];
		zs++;
		sq[zs]=e;
		p[e]+=-e*2+1;
	}
	if(!bad)
	{
		for(ii=0;ii<2;ii++)
		{
			u=-ii*2+1;
			for(i=p[ii];i<=n&&i&&a[i]>a[i-u];i+=u);
			mxe=max(mxe,{abs(i-p[ii]),ii});
		}
		mx=mxe.fr;
		e=mxe.sc;
		for(i=0;i<mx;i++)
		{
			zs++;
			sq[zs]=e;
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%c","LR"[sq[i]]);
	}
	printf("\n");
}