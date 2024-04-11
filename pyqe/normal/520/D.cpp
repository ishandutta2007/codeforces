#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dg[2][100069],dv=1e9+9;
map<pair<long long,long long>,long long> pst;
vector<long long> al[2][100069];
multiset<long long> ms;
bitset<100069> vtd;

int main()
{
	long long i,j,r,ii,u,k,l,sz,tg,szz,x,y,z=0;
	multiset<long long>::iterator it;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		pst[{x,y}]=i;
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(j=-1;j<=1;j++)
			{
				k=pst[{x+j,y+u}];
				if(k)
				{
					al[ii][i].push_back(k);
					al[!ii][k].push_back(i);
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		sz=al[1][i].size();
		dg[0][i]=sz;
		if(sz==1)
		{
			dg[1][al[1][i][0]]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!dg[1][i])
		{
			ms.insert(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(i%2)
		{
			it=prev(ms.end());
		}
		else
		{
			it=ms.begin();
		}
		k=*it;
		ms.erase(it);
		z=(z*n+k-1)%dv;
		vtd[k]=1;
		sz=al[0][k].size();
		for(j=0;j<sz;j++)
		{
			l=al[0][k][j];
			if(!vtd[l])
			{
				dg[0][l]--;
				if(dg[0][l]==1)
				{
					szz=al[1][l].size();
					for(r=0;r<szz;r++)
					{
						tg=al[1][l][r];
						if(!vtd[tg])
						{
							if(!dg[1][tg])
							{
								ms.erase(tg);
							}
							dg[1][tg]++;
						}
					}
				}
			}
		}
		if(dg[0][k]==1)
		{
			sz=al[1][k].size();
			for(j=0;j<sz;j++)
			{
				l=al[1][k][j];
				if(!vtd[l])
				{
					dg[1][l]--;
					if(!dg[1][l])
					{
						ms.insert(l);
					}
				}
			}
		}
	}
	printf("%lld\n",z);
}