#include <bits/stdc++.h>

using namespace std;

long long n,ps[26][200069];

long long bf(long long x,long long ln,long long w)
{
	if(ln==1)
	{
		return ln-(ps[w][x]-ps[w][x-1]);
	}
	else
	{
		return min(ln/2-(ps[w][x+ln/2-1]-ps[w][x-1])+bf(x+ln/2,ln/2,w+1),ln/2-(ps[w][x+ln-1]-ps[w][x+ln/2-1])+bf(x,ln/2,w+1));
	}
}

int main()
{
	long long t,rr,i,j;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<26;j++)
			{
				ps[j][i]=ps[j][i-1];
			}
			ps[s[i-1]-'a'][i]++;
		}
		printf("%lld\n",bf(1,n,0));
	}
}