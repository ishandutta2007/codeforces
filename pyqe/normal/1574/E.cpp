#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,m,c[3][2],fq[2][1000069][2],pwk;
map<long long,long long> a[1000069];

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

void ins(long long y,long long x,long long w)
{
	long long ii;
	
	a[y][x]=w+1;
	c[0][(y+x+w)%2]++;
	for(ii=0;ii<2;ii++)
	{
		c[1][ii]+=fq[ii][y][0]+fq[ii][y][1]==0;
		c[2][ii]+=!fq[ii][y][(x+w)%2]&&fq[ii][y][(x+w+1)%2];
		fq[ii][y][(x+w)%2]++;
		swap(y,x);
	}
}

void ers(long long y,long long x)
{
	long long ii,w;
	
	if(a[y][x])
	{
		w=a[y][x]-1;
		a[y][x]=0;
		c[0][(y+x+w)%2]--;
		for(ii=0;ii<2;ii++)
		{
			fq[ii][y][(x+w)%2]--;
			c[1][ii]-=fq[ii][y][0]+fq[ii][y][1]==0;
			c[2][ii]-=!fq[ii][y][(x+w)%2]&&fq[ii][y][(x+w+1)%2];
			swap(y,x);
		}
	}
}

int main()
{
	long long t,rr,y,x,w,z;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&y,&x,&w);
		ers(y,x);
		if(w+1)
		{
			ins(y,x,w);
		}
		z=(pw(2,n-c[1][0])*!c[2][0]+pw(2,m-c[1][1])*!c[2][1]+dv-(2-(c[0][0]||c[0][1]))*(!c[0][0]||!c[0][1]))%dv;
		printf("%lld\n",z);
	}
}