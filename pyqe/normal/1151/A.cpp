#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],ky[4]={0,2,19,6};

int main()
{
	long long i,j,k,df,mn=1e18;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'A';
	}
	for(i=1;i<=n-3;i++)
	{
		k=0;
		for(j=0;j<4;j++)
		{
			df=abs(a[i+j]-ky[j]);
			k+=min(df,26-df);
		}
		mn=min(mn,k);
	}
	printf("%lld\n",mn);
}