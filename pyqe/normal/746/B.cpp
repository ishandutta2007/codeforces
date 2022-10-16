#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	for(i=1;i<=n;i++)
	{
		printf("%c",(char)a[max(n+1-i*2,n-(n-i)*2)]+'a');
	}
	printf("\n");
}