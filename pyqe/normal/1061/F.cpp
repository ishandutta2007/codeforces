#include <bits/stdc++.h>

using namespace std;

long long n,d,dh=0,nn,a[69];
bitset<1569> vtd,spc;

bool qr(long long x,long long x2,long long x3)
{
	string s;
	
	printf("? %lld %lld %lld\n",x,x2,x3);
	fflush(stdout);
	cin>>s;
	return s[0]=='Y';
}

long long ffh(long long x)
{
	long long i,p=0;
	
	for(i=1;i<=n;i++)
	{
		if(!p||qr(x,p,i))
		{
			p=i;
		}
	}
	return p;
}

long long ds(long long x,long long y)
{
	long long i,z=-1;
	
	for(i=1;i<=n;i++)
	{
		z+=qr(x,i,y);
	}
	return z;
}

long long fnr(long long x,long long y)
{
	long long i;
	
	for(i=1;i<=n;i++)
	{
		if(i!=x&&qr(x,i,y))
		{
			y=i;
		}
	}
	return y;
}

void fsb(long long x,long long y)
{
	long long i;
	
	nn=0;
	for(i=1;i<=n;i++)
	{
		spc[i]=qr(x,y,i);
		nn+=spc[i];
	}
}

int main()
{
	long long i,j,k,w,p,z;
	
	scanf("%lld%lld",&n,&d);
	a[0]=1;
	for(k=1;k<n;k=k*d+1)
	{
		dh++;
		a[dh]=k;
	}
	if(dh==1)
	{
		k=ffh(1);
		w=ds(1,k);
		if(w==1)
		{
			z=1;
		}
		else
		{
			z=fnr(1,k);
		}
	}
	else if(dh==2)
	{
		p=0;
		for(i=1;i<=n;i++)
		{
			k=ffh(i);
			w=ds(i,k);
			if(w%2)
			{
				k=i;
			}
			else
			{
				k=fnr(i,k);
			}
			if(!p)
			{
				p=k;
			}
			else if(k!=p)
			{
				z=fnr(p,k);
				break;
			}
		}
	}
	else
	{
		for(p=1;1;)
		{
			vtd.reset();
			for(i=1;i<=n;i++)
			{
				if(i!=p&&!vtd[i])
				{
					fsb(i,p);
					for(j=0;j<=dh&&a[j]!=nn;j++);
					if(j>dh)
					{
						for(j=1;j<=n;j++)
						{
							vtd[j]=vtd[j]||!spc[j];
						}
					}
					else
					{
						p=fnr(p,i);
						break;
					}
				}
			}
			if(i>n)
			{
				z=p;
				break;
			}
		}
	}
	printf("! %lld\n",z);
	fflush(stdout);
}