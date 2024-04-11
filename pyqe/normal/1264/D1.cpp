#include <bits/stdc++.h>

using namespace std;

long long n,a[1000069],fq[2][2][1000069],fc[1000069],ifc[1000069],pwk,dv=998244353;

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
	long long i,ii,jj,u,k,l,w,ww,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		a[i]=(s[i-1]=='(')-(s[i-1]=='?');
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=1+(n-1)*ii;i&&i<=n;i+=u)
		{
			for(jj=0;jj<2;jj++)
			{
				fq[ii][jj][i]=fq[ii][jj][i-u]+(a[i]==jj);
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		k=i-fq[0][0][i]-fq[0][1][i];
		l=n-i-fq[1][0][i+1]-fq[1][1][i+1];
		w=fq[0][1][i];
		ww=fq[1][0][i+1];
		z=(z+cb(k+l-1,k+w-ww)*k+cb(k+l,k+w-ww)*w)%dv;
	}
	printf("%lld\n",z);
}