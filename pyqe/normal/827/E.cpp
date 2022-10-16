#include <bits/stdc++.h>

using namespace std;

const long long d=20,prt=3,dv=998244353;
long long n,nn,pc[(1ll<<d)+1],a[2][1ll<<d],pwk,sq[500069],zs=0;
bitset<500069> spc;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

inline void fft(long long sz,long long ca[],bool iv)
{
	long long i,j,r,k,l,p;
	
	for(i=0;i<sz;i++)
	{
		for(k=0,j=0;1ll<<j<sz;j++)
		{
			k=k<<1|i>>j&1;
		}
		if(i<k)
		{
			swap(ca[i],ca[k]);
		}
	}
	for(i=1;1ll<<i<=sz;i++)
	{
		for(j=0;j<sz;j+=1ll<<i)
		{
			for(r=0;r<1ll<<i-1;r++)
			{
				k=ca[j+r];
				l=ca[j+r+(1ll<<i-1)];
				p=r<<d-i;
				if(iv)
				{
					p=(1ll<<d)-p;
				}
				l=l*pc[p]%dv;
				ca[j+r]=(k+l)%dv;
				ca[j+r+(1ll<<i-1)]=(k+dv-l)%dv;
			}
		}
	}
	if(iv)
	{
		k=pw(sz,dv-2);
		for(i=0;i<sz;i++)
		{
			ca[i]=ca[i]*k%dv;
		}
	}
}

int main()
{
	long long t,rr,i,j,ii,k,p;
	char ch;
	
	k=pw(prt,dv-1>>d);
	pc[0]=1;
	for(i=1;i<=1ll<<d;i++)
	{
		pc[i]=pc[i-1]*k%dv;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(nn=1;nn<n<<1;nn<<=1);
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<nn;i++)
			{
				a[ii][i]=0;
			}
		}
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			k=(ch=='K')-(ch=='?');
			if(k!=-1)
			{
				p=i;
				if(k)
				{
					p=n-1-p;
				}
				a[k][p]++;
			}
		}
		for(ii=0;ii<2;ii++)
		{
			fft(nn,a[ii],0);
		}
		for(i=0;i<nn;i++)
		{
			a[0][i]=a[0][i]*a[1][i]%dv;
		}
		fft(nn,a[0],1);
		for(i=1;i<n;i++)
		{
			spc[i]=a[0][n-1-i]||a[0][n-1+i];
		}
		zs=0;
		for(i=1;i<n;i++)
		{
			for(j=i;j<n;j+=i)
			{
				spc[i]=spc[i]||spc[j];
			}
			if(!spc[i])
			{
				zs++;
				sq[zs]=i;
			}
		}
		zs++;
		sq[zs]=n;
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}