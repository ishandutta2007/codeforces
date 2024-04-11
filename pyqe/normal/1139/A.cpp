#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,z=0;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'0';
		z+=i*!(k%2);
	}
	printf("%lld\n",z);
}