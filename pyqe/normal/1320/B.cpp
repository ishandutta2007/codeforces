#include <bits/stdc++.h>

using namespace std;

long long n,m,ln,a[200069],nr[200069],sr[200069];
vector<long long> al[200069];
queue<long long> q;

int main()
{
	long long i,k,l,w,sz,z[2]={0,0};
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[l].push_back(k);
	}
	scanf("%lld",&ln);
	for(i=1;i<=ln;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		nr[i]=1e18;
	}
	q.push(a[ln]);
	nr[a[ln]]=0;
	for(;!q.empty();)
	{
		k=q.front();
		w=nr[k];
		q.pop();
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			if(w+1<nr[l])
			{
				q.push(l);
				nr[l]=w+1;
				sr[l]=0;
			}
			if(w+1==nr[l])
			{
				if(!sr[l]||sr[l]==k)
				{
					sr[l]=k;
				}
				else
				{
					sr[l]=-1;
				}
			}
		}
	}
	for(i=1;i<=ln-1;i++)
	{
		if(nr[a[i]]-1==nr[a[i+1]])
		{
			z[1]+=sr[a[i]]==-1;
		}
		else
		{
			z[0]++;
			z[1]++;
		}
	}
	printf("%lld %lld\n",z[0],z[1]);
}