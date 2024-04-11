#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

vector<pair<bitset<30>,bitset<30>>> v;
bitset<30> lh,rh,bs,bs2;

int main()
{
	long long t,rr,i,j,r,k,l,sz=0,ln,z=0;
	bool bad,bad2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		v.clear();
		sz=0;
		scanf("%lld%lld",&k,&l);
		z=0;
		if(!l)
		{
			printf("1\n");
			continue;
		}
		if(!k)
		{
			k++;
			z+=l*2+1;
		}
		lh.reset();
		rh.reset();
		for(i=0;k>0;k/=2,i++)
		{
			lh[i]=k%2;
		}
		for(i=0;l>0;l/=2,i++)
		{
			rh[i]=l%2;
		}
		for(i=29;!rh[i];i--);
		ln=i;
		if(lh[ln])
		{
			printf("%lld\n",z);
			continue;
		}
		for(bs=lh;1;)
		{
			bs2=bs;
			for(i=0;!bs[i];i++)
			{
				bs2[i]=1;
			}
			v.push_back({bs,bs2});
			sz++;
			bs=bs2;
			for(i=0;bs[i];i++)
			{
				bs[i]=0;
			}
			bs[i]=1;
			for(i=29;!bs[i];i--);
			if(i==ln)
			{
				break;
			}
		}
		for(bs=rh;1;)
		{
			bs2=bs;
			for(i=0;i<ln&&bs2[i];i++)
			{
				bs2[i]=0;
			}
			v.push_back({bs2,bs});
			sz++;
			bs=bs2;
			for(i=0;!bs[i];i++)
			{
				bs[i]=1;
			}
			bs[i]=0;
			for(i=29;!bs[i];i--);
			if(i<ln)
			{
				break;
			}
		}
		for(i=0;i<sz;i++)
		{
			for(j=0;j<sz;j++)
			{
				bad=0;
				for(r=29;r>=0&&v[i].fr[r]==v[i].sc[r]&&v[j].fr[r]==v[j].sc[r];r--)
				{
					if(v[i].fr[r]&&v[j].fr[r])
					{
						bad=1;
						break;
					}
				}
				if(bad)
				{
					continue;
				}
				bad=0;
				bad2=0;
				k=1;
				for(r=0;r<30&&!(bad&&bad2);r++)
				{
					if(v[i].fr[r]==v[i].sc[r])
					{
						bad=1;
					}
					if(v[j].fr[r]==v[j].sc[r])
					{
						bad2=1;
					}
					if(!bad&&!bad2)
					{
						k*=3;
					}
					else if((!bad&&!v[j].fr[r])||(!bad2&&!v[i].fr[r]))
					{
						k*=2;
					}
				}
				z+=k;
			}
		}
		printf("%lld\n",z);
	}
}