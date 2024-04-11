#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,a[100069][2],fc[200069],ifc[200069],pwk;

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

inline long long cb(long long x,long long y)
{
	if(x<y||y<0)
	{
		return 0;
	}
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long i,ii,jj,c[2]={0,0},ml=1,z;
	bool bad[2]={0,0};
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf(" %c",&ch);
			a[i][ii]=(ch=='W')-(ch=='?');
			if(a[i][ii]!=-1)
			{
				c[a[i][ii]]++;
			}
		}
		if(a[i][0]==-1&&a[i][1]==-1)
		{
			ml=ml*2%dv;
		}
		if(a[i][0]!=-1&&a[i][1]!=-1&&a[i][0]==a[i][1])
		{
			ml=0;
		}
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				bad[ii]|=a[i][jj]!=-1&&a[i][jj]!=(ii^jj);
			}
		}
	}
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n*2;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	z=(cb(n*2-c[0]-c[1],n-c[0])+dv-ml+!bad[0]+!bad[1])%dv;
	printf("%lld\n",z);
}