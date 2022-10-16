#include <bits/stdc++.h>

using namespace std;

const long long d=30;
long long n,nn,a[100069],as[d][100069],ca[d];
vector<long long> vl[d][100069];

int main()
{
	long long tt,rrr,t,rr,i,j,k,l,sz,p,sm,sm2,z;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			for(j=0;j<d;j++)
			{
				as[j][i]=a[i]>>j;
				vl[j][i].clear();
			}
		}
		for(i=0;i<d;i++)
		{
			sort(as[i]+1,as[i]+n+1);
			for(j=1;j<=n;j++)
			{
				p=lower_bound(as[i]+1,as[i]+n+1,a[j]>>i)-as[i];
				vl[i][p].push_back(j);
			}
		}
		scanf("%lld",&t);
		for(rr=0;rr<t;rr++)
		{
			scanf("%lld%lld",&k,&l);
			z=0;
			nn=0;
			for(i=d-1;i>=0;i--)
			{
				z<<=1;
				p=lower_bound(as[i]+1,as[i]+n+1,z)-as[i];
				sm=0;
				if(p<=n&&as[i][p]==z)
				{
					sm=upper_bound(vl[i][p].begin(),vl[i][p].end(),l)-lower_bound(vl[i][p].begin(),vl[i][p].end(),k);
				}
				sm2=sm;
				for(j=0;j<nn;j++)
				{
					sm2+=!(ca[j]>>i&1);
				}
				if(sm2>=2)
				{
					sz=nn;
					nn=0;
					for(j=0;j<sz;j++)
					{
						if(!(ca[j]>>i&1))
						{
							ca[nn]=ca[j];
							nn++;
						}
					}
				}
				else
				{
					z|=1;
					if(sm)
					{
						ca[nn]=a[*lower_bound(vl[i][p].begin(),vl[i][p].end(),k)];
						nn++;
					}
				}
			}
			printf("%lld\n",z);
		}
	}
}