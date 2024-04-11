#include <bits/stdc++.h>

using namespace std;

long long n,m,a[1069][1069];
map<pair<long long,long long>,pair<long long,long long>> pr;

pair<long long,long long> fd(pair<long long,long long> x)
{
	if(pr[x]!=x)
	{
		pr[x]=fd(pr[x]);
	}
	return pr[x];
}

void chk(long long y1,long long x1,long long y2,long long x2)
{
	if(a[y1][x1]!=a[y2][x2])
	{
		return;
	}
	if(fd({y1,x1})==fd({y2,x2}))
	{
		printf("Yes\n");
		exit(0);
	}
	pr[fd({y2,x2})]=fd({y1,x1});
}

int main()
{
	long long i,j;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			a[i][j]=s[j-1]-'A';
			pr[{i,j}]={i,j};
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i>1)
			{
				chk(i,j,i-1,j);
			}
			if(j>1)
			{
				chk(i,j,i,j-1);
			}
		}
	}
	printf("No\n");
}