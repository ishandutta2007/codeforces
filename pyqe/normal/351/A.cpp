#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,fq=0;

int main()
{
	long long i,j,ln,k,kk,sm=0,tg1,tg2;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n+n;i++)
	{
		cin>>s;
		ln=s.length();
		for(k=0,j=ln-3;j<ln;j++)
		{
			k=k*10+(s[j]-'0');
		}
		if(k)
		{
			nn++;
			sm+=k;
		}
		else
		{
			fq++;
		}
	}
	tg1=max(min(sm/1000,n),n-fq);
	tg2=max(min(sm/1000+1,n),n-fq);
	k=min(abs(sm-1000*tg1),abs(sm-1000*tg2));
	printf("%lld.",k/1000);
	if(!(k%1000))
	{
		printf("000\n");
		return 0;
	}
	for(kk=k%1000;kk<100;kk*=10)
	{
		printf("0");
	}
	printf("%lld\n",k%1000);
}