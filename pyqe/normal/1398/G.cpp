#include <bits/stdc++.h>

using namespace std;

const long long ma=5e5,dv=998244353,prt=3;
long long n,d,d2,pc[1ll<<19],a[2][1ll<<19],sq[1000069],pwk;

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

void fft(long long nn,long long ca[1ll<<19],bool iv)
{
	long long i,j,r,k,l,p;
	
	for(i=0;i<nn;i++)
	{
		k=i;
		p=0;
		for(j=0;1ll<<j<nn;j++)
		{
			p=p<<1|k&1;
			k>>=1;
		}
		if(i<p)
		{
			swap(ca[i],ca[p]);
		}
	}
	for(i=1;1ll<<i<=nn;i++)
	{
		for(j=0;j<nn;j+=1ll<<i)
		{
			for(r=0;r<1ll<<i-1;r++)
			{
				k=ca[j+r];
				l=ca[j+r+(1ll<<i-1)];
				p=r*d>>i;
				if(!iv)
				{
					l=l*pc[p]%dv;
				}
				else
				{
					l=l*pc[(d-p)%d]%dv;
				}
				ca[j+r]=(k+l)%dv;
				ca[j+r+(1ll<<i-1)]=(k+dv-l)%dv;
			}
		}
	}
	if(iv)
	{
		k=pw(nn,dv-2);
		for(i=0;i<nn;i++)
		{
			ca[i]=ca[i]*k%dv;
		}
	}
}

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld%lld%lld",&n,&d,&d2);
	for(i=0;1ll<<i<=d;i++);
	d=1ll<<i+1;
	pc[0]=1;
	k=pw(prt,(dv-1)/d);
	for(i=1;i<d;i++)
	{
		pc[i]=pc[i-1]*k%dv;
	}
	for(i=0;i<n+1;i++)
	{
		scanf("%lld",&k);
		a[0][k]=1;
		a[1][d/2-1-k]=1;
	}
	fft(d,a[0],0);
	fft(d,a[1],0);
	for(i=0;i<d;i++)
	{
		a[0][i]=a[0][i]*a[1][i]%dv;
	}
	fft(d,a[0],1);
	for(i=1;i<=ma;i++)
	{
		sq[i]=-1;
	}
	for(i=1;i<=d/2;i++)
	{
		if(a[0][d/2-1+i])
		{
			for(j=i+d2;j<=ma;j+=i+d2)
			{
				sq[j]=(i+d2)*2;
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		printf("%lld%c",sq[k/2]," \n"[rr==t-1]);
	}
}