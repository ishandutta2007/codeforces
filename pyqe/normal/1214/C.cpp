#include <bits/stdc++.h>

using namespace std;

long long n,ps[200069];

int main()
{
	long long i,mn=0;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+(s[i-1]=='(')*2-1;
		mn=min(mn,ps[i]);
	}
	if(ps[n]==0&&mn>=-1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}