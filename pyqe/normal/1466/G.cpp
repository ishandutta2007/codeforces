#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7,iv=5e8+4;
long long n,m,nn,a[169],ky[100069],p2[100069],ip2[100069],ps[26][100069],sa[1000069],ca[1000069];

long long rk(long long x,long long ub,long long st)
{
	if(!nn)
	{
		return p2[ub];
	}
	else if(x>ub)
	{
		return 0;
	}
	else if(st+(1ll<<x-1)<=nn)
	{
		long long i,ii,sm=0;
		
		for(ii=0;ii<2;ii++)
		{
			for(i=st+(ii<<x-1);i<=nn;i+=1ll<<x)
			{
				if(ca[i]!=ky[x])
				{
					break;
				}
			}
			if(i>nn)
			{
				sm=(sm+rk(x+1,ub,st+((long long)!ii<<x-1)))%dv;
			}
		}
		return sm;
	}
	else
	{
		return (ps[ca[st]][ub]+dv-ps[ca[st]][x-1])*ip2[n-ub]%dv;
	}
}

int main()
{
	long long t,rr,i,j,k,ln,z;
	char ch;
	string s;
	
	scanf("%lld%lld",&n,&t);
	cin>>s;
	m=s.length();
	for(i=0;i<m;i++)
	{
		a[i]=s[i]-'a';
	}
	p2[0]=1;
	ip2[0]=1;
	for(i=1;i<=n;i++)
	{
		p2[i]=p2[i-1]*2%dv;
		ip2[i]=ip2[i-1]*iv%dv;
	}
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		ky[i]=ch-'a';
		for(j=0;j<26;j++)
		{
			ps[j][i]=ps[j][i-1];
		}
		ps[ky[i]][i]=(ps[ky[i]][i]+p2[n-i])%dv;
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		cin>>s;
		ln=s.length();
		for(i=0;i<ln;i++)
		{
			sa[i]=s[i]-'a';
		}
		z=0;
		for(i=0;i<m+1;i++)
		{
			nn=0;
			for(j=0;j<ln;j++)
			{
				if((i+j)%(m+1)<m)
				{
					if(sa[j]!=a[(i+j)%(m+1)])
					{
						break;
					}
				}
				else
				{
					nn++;
					ca[nn]=sa[j];
				}
			}
			if(j>=ln)
			{
				z=(z+rk(1,k,1))%dv;
			}
		}
		printf("%lld\n",z);
	}
}