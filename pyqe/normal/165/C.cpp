#include <bits/stdc++.h>

using namespace std;

long long n,d,nn=0,pst[1000069];
bitset<1000069> a;

int main()
{
	long long i,z=0;
	string s;
	
	scanf("%lld",&d);
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	a[0]=1;
	a[n+1]=1;
	for(i=0;i<=n+1;i++)
	{
		if(a[i])
		{
			nn++;
			pst[nn]=i;
		}
	}
	for(i=d+2;i<=nn;i++)
	{
		if(!d)
		{
			z+=(pst[i]-pst[i-1])*(pst[i]-pst[i-1]-1)/2;
		}
		else
		{
			z+=(pst[i]-pst[i-1])*(pst[i-d]-pst[i-d-1]);
		}
	}
	printf("%lld\n",z);
}