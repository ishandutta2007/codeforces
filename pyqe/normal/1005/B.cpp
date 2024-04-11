#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][200069];

int main()
{
	long long i,ii;
	string s;
	
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		n[ii]=s.length();
		for(i=1;i<=n[ii];i++)
		{
			a[ii][n[ii]+1-i]=s[i-1]-'a';
		}
	}
	for(i=0;i+1<=min(n[0],n[1])&&a[0][i+1]==a[1][i+1];i++);
	printf("%lld\n",n[0]+n[1]-i*2);
}