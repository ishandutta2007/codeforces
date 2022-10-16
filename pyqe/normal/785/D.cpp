#include <bits/stdc++.h>

using namespace std;

long long n,fc[200069],ifc[200069],ps[2][200069],pwk,dv=1e9+7;
bitset<200069> a;

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

int main()
{
	long long i,ii,u,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
		a[i]=s[i-1]=='(';
	}
	for(ii=0;ii<2;ii++)
	{
		u=ii*2-1;
		for(i=n-(n-1)*ii;i&&i<=n;i+=u)
		{
			ps[ii][i]=ps[ii][i-u]+(a[i]==ii);
		}
	}
	for(i=1;i<=n;i++)
	{
		z=(z+cb(ps[1][i-1]+ps[0][i+1],ps[0][i+1]-1)*a[i])%dv;
	}
	printf("%lld\n",z);
}