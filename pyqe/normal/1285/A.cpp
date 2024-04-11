#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];

int main()
{
	long long i;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		fq[s[i-1]=='R']++;
	}
	printf("%lld\n",fq[0]+fq[1]+1);
}