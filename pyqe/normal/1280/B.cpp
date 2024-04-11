#include <bits/stdc++.h>

using namespace std;

long long n,m,ps[69][69];
bitset<69> a[69];

long long sm(long long y1,long long x1,long long y2,long long x2)
{
	return max(ps[y2][x2]-ps[y1-1][x2]-ps[y2][x1-1]+ps[y1-1][x1-1],0ll);
}

int main()
{
	long long t,rr,i,j;
	string s;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			cin>>s;
			for(j=1;j<=m;j++)
			{
				a[i][j]=s[j-1]=='A';
				ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+a[i][j];
			}
		}
		bad=1;
		for(i=2;i<n;i++)
		{
			if(sm(i,1,i,m)==m)
			{
				bad=0;
			}
		}
		for(i=2;i<m;i++)
		{
			if(sm(1,i,n,i)==n)
			{
				bad=0;
			}
		}
		if(sm(1,1,n,m)==n*m)
		{
			printf("0\n");
		}
		else if(sm(1,1,1,m)==m||sm(1,1,n,1)==n||sm(n,1,n,m)==m||sm(1,m,n,m)==n)
		{
			printf("1\n");
		}
		else if(a[1][1]||a[1][m]||a[n][1]||a[n][m]||!bad)
		{
			printf("2\n");
		}
		else if(sm(1,2,1,m-1)>0||sm(2,1,n-1,1)>0||sm(n,2,n,m-1)>0||sm(2,m,n-1,m)>0)
		{
			printf("3\n");
		}
		else if(sm(1,1,n,m))
		{
			printf("4\n");
		}
		else
		{
			printf("MORTAL\n");
		}
	}
}