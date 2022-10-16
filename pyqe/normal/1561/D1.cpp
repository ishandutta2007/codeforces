#include <bits/stdc++.h>

using namespace std;

long long n,dv,ps[4000069];

int main()
{
	long long i,j;
	
	scanf("%lld%lld",&n,&dv);
	ps[n]=1;
	for(i=n-1;i;i--)
	{
		ps[i]=ps[i+1];
		for(j=2;i*j<=n;j++)
		{
			ps[i]=(ps[i]+ps[i*j]+dv-ps[min((i+1)*j,n+1)])%dv;
		}
		ps[i]=(ps[i]+ps[i+1])%dv;
	}
	printf("%lld\n",(ps[1]+dv-ps[2])%dv);
}