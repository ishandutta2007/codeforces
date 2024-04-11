#include <bits/stdc++.h>

using namespace std;

long long n,m,d,bd[4];
vector<long long> pst[4][100069];

int main()
{
	long long i,j,ii,k,l,z=1,y,x,p;
	bool ft=1;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=0;i<d;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(ii=0;ii<4;ii++)
		{
			pst[ii][k].push_back(l);
			l=m+1-l;
			swap(k,l);
			swap(n,m);
		}
	}
	for(ii=0;ii<4;ii++)
	{
		for(i=1;i<=n;i++)
		{
			sort(pst[ii][i].begin(),pst[ii][i].end());
			pst[ii][i].push_back(m+1);
		}
		bd[ii]=m+1;
		swap(n,m);
	}
	y=1;
	x=1;
	for(ii=0;1;ii=(ii+1)%4)
	{
		p=min(bd[ii],*upper_bound(pst[ii][y].begin(),pst[ii][y].end(),x))-1;
		k=p-x;
		bd[(ii+3)%4]=n+1-y;
		x=p;
		z+=k;
		if(k==0&&!ft)
		{
			break;
		}
		ft=0;
		x=m+1-x;
		swap(y,x);
		swap(n,m);
	}
	if(z==n*m-d)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}