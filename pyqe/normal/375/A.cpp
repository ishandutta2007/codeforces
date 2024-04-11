#include <bits/stdc++.h>

using namespace std;

long long n,fq[10],dv7[7]={1869,1968,1689,6198,1698,1986,1896};

int main()
{
	long long i,j,k,sm=0;
	string s;
	
	cin>>s;
	n=s.length();
	fq[1]--;
	fq[6]--;
	fq[8]--;
	fq[9]--;
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'0';
		fq[k]++;
	}
	for(i=1;i<10;i++)
	{
		for(j=0;j<fq[i];j++)
		{
			printf("%lld",i);
			sm=(sm*10+i)%7;
		}
	}
	sm=sm*10000%7;
	printf("%lld",dv7[(7-sm)%7]);
	for(i=0;i<fq[0];i++)
	{
		printf("0");
	}
	printf("\n");
}