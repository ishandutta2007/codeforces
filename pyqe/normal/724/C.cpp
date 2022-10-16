#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n[2],ft[4][200069];

int main()
{
	long long t,rr,i,ii,iii,k,pt[2]={0,0},pp=0,c=0,mn,e,p[2];
	pair<long long,long long> mne;
	
	scanf("%lld%lld%lld",n,n+1,&t);
	for(ii=0;ii<4;ii++)
	{
		for(i=0;i<=n[0]+n[1];i++)
		{
			ft[ii][i]=-1;
		}
	}
	for(;1;)
	{
		ft[pp][pt[0]-pt[1]+n[1]]=c;
		if(n[0]-pt[0]==n[1]-pt[1])
		{
			break;
		}
		mne=min(mp(n[0]-pt[0],0),{n[1]-pt[1],1});
		mn=mne.fr;
		e=mne.sc;
		pt[e]=0;
		pt[!e]+=mn;
		pp^=1<<e;
		c+=mn;
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",pt,pt+1);
		mn=1e18;
		for(ii=0;ii<4;ii++)
		{
			for(iii=0;iii<2;iii++)
			{
				p[iii]=pt[iii];
				if(ii>>iii&1)
				{
					p[iii]=n[iii]-p[iii];
				}
			}
			k=ft[ii][p[0]-p[1]+n[1]];
			if(k!=-1)
			{
				mn=min(mn,k+min(p[0],p[1]));
			}
		}
		if(mn==1000000000000000000)
		{
			mn=-1;
		}
		printf("%lld\n",mn);
	}
}