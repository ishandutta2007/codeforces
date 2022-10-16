#include <bits/stdc++.h>

using namespace std;

long long n,d,lb,rb,a[100069];

int main()
{
	long long i,j,k,sm=0;
	string s;
	
	scanf("%lld%lld%lld",&d,&lb,&rb);
	cin>>s;
	n=s.length();
	if(n<lb*d||n>rb*d)
	{
		printf("No solution\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	for(i=1;i<=d;i++)
	{
		k=max(min(n-lb*d-(rb-lb)*(i-1)+lb,rb),lb);
		for(j=sm+1;j<=sm+k;j++)
		{
			printf("%c",(char)a[j]+'a');
		}
		sm+=k;
		printf("\n");
	}
}