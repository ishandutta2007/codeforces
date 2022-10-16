#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,pr[2500569],a[2500569],sq[2500569],zs=0;
queue<vector<long long>> q;

int main()
{
	long long i,j,k,l,w,sz,ww,p;
	vector<long long> v,vv;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n*(d+1);i++)
	{
		pr[i]=-1;
	}
	q.push({0});
	pr[0]=0;
	for(;!q.empty();)
	{
		v=q.front();
		q.pop();
		sz=v.size();
		for(i=0;i<10;i++)
		{
			vv.clear();
			for(j=0;j<sz;j++)
			{
				k=v[j]%n;
				w=v[j]/n;
				l=(k*10+i)%n;
				ww=w+i;
				p=ww*n+l;
				if(ww<=d&&pr[p]==-1)
				{
					vv.push_back(p);
					pr[p]=v[j];
					a[p]=i;
				}
			}
			if(!vv.empty())
			{
				q.push(vv);
			}
		}
	}
	if(pr[n*d]==-1)
	{
		printf("-1\n");
		return 0;
	}
	for(p=n*d;p;p=pr[p])
	{
		zs++;
		sq[zs]=a[p];
	}
	for(i=zs;i;i--)
	{
		printf("%lld",sq[i]);
	}
	printf("\n");
}