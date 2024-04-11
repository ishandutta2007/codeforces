#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353,prt=3;
long long n,m,mm,fq[300069],aa[5],pc[1ll<<19],fc[1ll<<19],ifc[1ll<<19],a[5][2][1ll<<19],pwk;

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

long long cb(long long x,long long y)
{
	if(x<y||y<0)
	{
		return 0;
	}
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
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
				p=r*mm>>i;
				if(!iv)
				{
					l=l*pc[p]%dv;
				}
				else
				{
					l=l*pc[(mm-p)%mm]%dv;
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
	long long t,rr,i,j,k,c,c2,p,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",aa+i);
	}
	for(mm=1;mm<=n;mm<<=1);
	pc[0]=1;
	k=pw(prt,(dv-1)/mm);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<mm;i++)
	{
		pc[i]=pc[i-1]*k%dv;
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(i=0;i<m;i++)
	{
		c=0;
		c2=0;
		for(j=1;j<aa[i];j++)
		{
			c+=fq[j]==1;
			c2+=fq[j]>=2;
		}
		for(j=0;j<mm;j++)
		{
			a[i][0][j]=cb(c,j)*pw(2,j)%dv;
			a[i][1][j]=cb(c2*2,j);
		}
		fft(mm,a[i][0],0);
		fft(mm,a[i][1],0);
		for(j=0;j<mm;j++)
		{
			a[i][0][j]=(a[i][0][j]*a[i][1][j])%dv;
		}
		fft(mm,a[i][0],1);
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		z=0;
		for(i=0;i<m;i++)
		{
			p=k/2-aa[i]-1;
			if(p>=0&&p<mm)
			{
				z=(z+a[i][0][p])%dv;
			}
		}
		printf("%lld\n",z);
	}
}