#include <bits/stdc++.h>

using namespace std;

long long ln,n=0,a[300069],fq[300069],cl[300069];

int main()
{
	long long i;
	string s;
	
	cin>>s;
	ln=s.length();
	for(i=1;i<=ln;i++)
	{
		a[i]=s[i-1]-'A';
	}
	for(i=1;i<=ln;i++)
	{
		if(i==1||a[i]!=a[i-1])
		{
			n++;
		}
		fq[n]++;
		cl[n]=a[i];
	}
	if(n%2==0)
	{
		printf("0\n");
		return 0;
	}
	for(i=1;i<=n/2;i++)
	{
		if(cl[i]!=cl[n+1-i]||fq[i]+fq[n+1-i]<3)
		{
			printf("0\n");
			return 0;
		}
	}
	if(fq[n/2+1]<2)
	{
		printf("0\n");
	}
	else
	{
		printf("%lld\n",fq[n/2+1]+1);
	}
}