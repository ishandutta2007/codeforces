#include <bits/stdc++.h>

using namespace std;

long long n;
map<long long,long long> com;
queue<long long> q[6];

int main()
{
	long long i,k,z,ls;
	
	com[4]=0;
	com[8]=1;
	com[15]=2;
	com[16]=3;
	com[23]=4;
	com[42]=5;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		q[com[k]].push(i);
	}
	for(z=0;1;z++)
	{
		ls=0;
		for(i=0;i<6;i++)
		{
			for(;!q[i].empty()&&q[i].front()<=ls;q[i].pop());
			if(q[i].empty())
			{
				printf("%lld\n",n-z*6);
				return 0;
			}
			ls=q[i].front();
			q[i].pop();
		}
	}
}