#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,ln,a[1000069],sq[1000069];
deque<pair<long long,long long>> dq;

int main()
{
	long long i,j,k,l;
	
	scanf("%lld%lld",&n,&ln);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&m);
		for(j=1;j<=m;j++)
		{
			scanf("%lld",a+j);
		}
		a[m+1]=0;
		for(j=0;j<=ln;j++)
		{
			if(j<=m+1)
			{
				for(;!dq.empty()&&dq.back().fr<=a[j];dq.pop_back());
				dq.push_back({a[j],j});
			}
			for(;dq.front().sc<j-(ln-m);dq.pop_front());
			k=dq.front().fr;
			if(j)
			{
				sq[j]+=k-l;
			}
			l=k;
			if(j==m+1)
			{
				j=max(j,ln-m);
			}
		}
		for(;!dq.empty();dq.pop_front());
	}
	for(i=1;i<=ln;i++)
	{
		sq[i]+=sq[i-1];
		printf("%lld%c",sq[i]," \n"[i==ln]);
	}
}