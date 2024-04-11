#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

long long n,ls[100069],pr[100069],sq[100069];
queue<long long> q[100069];
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> superset;
superset pbds;

int main()
{
	long long i,k,p;
	
	scanf("%lld",&n);
	for(i=1;i<=n*2;i++)
	{
		if(i<=n)
		{
			scanf("%lld",&k);
		}
		else
		{
			k=i-n;
		}
		if(!ls[k])
		{
			pbds.insert(i);
		}
		else
		{
			pr[ls[k]]=i;
		}
		ls[k]=i;
	}
	pbds.insert(n*2+1);
	for(i=1;i<=n;i++)
	{
		q[1].push(i);
	}
	for(i=1;i<=n;i++)
	{
		for(;!q[i].empty();)
		{
			k=q[i].front();
			q[i].pop();
			p=*pbds.find_by_order(k);
			if(p<=n)
			{
				q[p].push(k);
			}
			sq[k]++;
		}
		pbds.erase(i);
		pbds.insert(pr[i]);
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}