#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,zs=0;
priority_queue<long long> pq;
pair<long long,long long> sq[300069];
string sy[3]={"insert","getMin","removeMin"};

void op(long long ky,long long w)
{
	zs++;
	sq[zs]={ky,w};
	if(!ky)
	{
		pq.push(-w);
	}
	else if(ky==2)
	{
		pq.pop();
	}
}

int main()
{
	long long i,ky,k;
	string s;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		for(ky=0;ky<3;ky++)
		{
			if(s==sy[ky])
			{
				break;
			}
		}
		if(ky!=2)
		{
			scanf("%lld",&k);
		}
		if(ky==1)
		{
			for(;!pq.empty()&&-pq.top()<k;op(2,0));
			if(pq.empty()||-pq.top()!=k)
			{
				op(0,k);
			}
		}
		else if(ky==2)
		{
			if(pq.empty())
			{
				op(0,0);
			}
		}
		op(ky,k);
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		ky=sq[i].fr;
		k=sq[i].sc;
		printf("%s",sy[ky].c_str());
		if(ky!=2)
		{
			printf(" %lld",k);
		}
		printf("\n");
	}
}