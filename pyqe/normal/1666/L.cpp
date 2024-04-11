#include <bits/stdc++.h>

using namespace std;

long long n,m,st,sr[200069],pr[200069],sq[200069],zs=0;
vector<long long> al[200069];
queue<long long> q;

int main()
{
	long long i,j,k,l,sz,p;
	
	scanf("%lld%lld%lld",&n,&m,&st);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
	}
	sr[st]=st;
	sz=al[st].size();
	for(i=0;i<sz;i++)
	{
		l=al[st][i];
		q.push(l);
		sr[l]=l;
		pr[l]=st;
	}
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			if(!sr[l])
			{
				q.push(l);
				sr[l]=sr[k];
				pr[l]=k;
			}
			else if(sr[l]!=st&&sr[l]!=sr[k])
			{
				zs=0;
				for(p=l;p;p=pr[p])
				{
					zs++;
					sq[zs]=p;
				}
				printf("Possible\n%lld\n",zs);
				for(j=zs;j;j--)
				{
					printf("%lld%c",sq[j]," \n"[j==1]);
				}
				zs=1;
				for(p=k;p;p=pr[p])
				{
					zs++;
					sq[zs]=p;
				}
				printf("%lld\n",zs);
				for(j=zs;j;j--)
				{
					printf("%lld%c",sq[j]," \n"[j==1]);
				}
				return 0;
			}
		}
	}
	printf("Impossible\n");
}