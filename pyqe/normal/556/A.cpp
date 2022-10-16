#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];

int main()
{
	long long i,k;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'0';
		fq[k]++;
	}
	printf("%lld\n",abs(fq[0]-fq[1]));
}