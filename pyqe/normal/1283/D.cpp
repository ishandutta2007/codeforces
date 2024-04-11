#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m;
map<long long,bool> vtd;
queue<pair<long long,long long>> q;
vector<long long> sq;

int main()
{
	long long i,ii,k,w,c=0,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		q.push({k,0});
		vtd[k]=1;
	}
	for(;c<m;)
	{
		k=q.front().fr;
		w=q.front().sc;
		q.pop();
		for(ii=k-1;ii<=k+1;ii+=2)
		{
			if(!vtd[ii])
			{
				q.push({ii,w+1});
				vtd[ii]=1;
				sq.push_back(ii);
				c++;
				z+=w+1;
				if(c==m)
				{
					break;
				}
			}
		}
	}
	printf("%lld\n",z);
	for(i=0;i<m;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==m-1]);
	}
}