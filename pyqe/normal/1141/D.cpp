#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,zs=0;
queue<long long> q[2][27];
pair<long long,long long> sq[150069];

int main()
{
	long long i,ii,k,l;
	string s;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'a';
			if(k=='?'-'a')
			{
				k=26;
			}
			q[ii][k].push(i);
		}
	}
	for(i=0;i<26;i++)
	{
		for(;!q[0][i].empty()&&!q[1][i].empty();)
		{
			k=q[0][i].front();
			l=q[1][i].front();
			q[0][i].pop();
			q[1][i].pop();
			zs++;
			sq[zs]={k,l};
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<26+ii;i++)
		{
			for(;!q[ii][26].empty()&&!q[!ii][i].empty();)
			{
				k=q[ii][26].front();
				l=q[!ii][i].front();
				q[ii][26].pop();
				q[!ii][i].pop();
				if(ii)
				{
					swap(k,l);
				}
				zs++;
				sq[zs]={k,l};
			}
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}