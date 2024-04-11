#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,spc[200069],nr[2][200069],px[200069];
vector<long long> al[200069];
queue<long long> q;
pair<long long,long long> dis[200069];

int main()
{
	long long i,ii,k,l,w,sz,mx=-1e18;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=d;i++)
	{
		scanf("%lld",spc+i);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			nr[ii][i]=1e18;
		}
		q.push(1+(n-1)*ii);
		nr[ii][1+(n-1)*ii]=0;
		for(;!q.empty();)
		{
			k=q.front();
			w=nr[ii][k];
			q.pop();
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l=al[k][i];
				if(w+1<nr[ii][l])
				{
					q.push(l);
					nr[ii][l]=w+1;
				}
			}
		}
	}
	for(i=1;i<=d;i++)
	{
		dis[i]={nr[0][spc[i]],nr[1][spc[i]]};
	}
	sort(dis+1,dis+d+1);
	px[d+1]=-1e18;
	for(i=d;i;i--)
	{
		px[i]=max(px[i+1],dis[i].sc);
	}
	for(i=1;i<=d;i++)
	{
		mx=max(mx,dis[i].fr+1+px[i+1]);
	}
	printf("%lld\n",min(nr[0][n],mx));
}