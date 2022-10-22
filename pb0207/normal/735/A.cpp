#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char s[101];

int n,k,g,t;

int main()
{
	cin>>n>>k;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='G')
			g=i;
		if(s[i]=='T')
			t=i;
	}
	if(g<t)
	{
		if((t-g)%k!=0)
		{
			puts("NO");
			exit(0);
		}
		while(g<t)
		{
			g+=k;
			if(s[g]=='#')
			{
				puts("NO");
				exit(0);
			}
		}
		puts("YES");
	}
	else
	{
		if((g-t)%k!=0)
		{
			puts("NO");
			exit(0);
		}
		while(t<g)
		{
			t+=k;
			if(s[t]=='#')
			{
				puts("NO");
				exit(0);
			}
		}
		puts("YES");
	}
}