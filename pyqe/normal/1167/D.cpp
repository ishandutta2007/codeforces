#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		k=s[i-1]=='(';
		printf("%lld",(i+k)%2);
	}
	printf("\n");
}