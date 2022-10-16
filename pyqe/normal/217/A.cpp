#include <bits/stdc++.h>

using namespace std;

map<pair<long long,long long>,pair<long long,long long>> pr;
map<pair<long long,long long>,bool> m;

pair<long long,long long> fnd(pair<long long,long long> k)
{
	if(pr[k]==k)
	{
		return k;
	}
	else
	{
		return fnd(pr[k]);
	}
}

int main()
{
	long long n,i,j,x,y,sz,c=0;
	vector<long long> xv[1069];
	vector<long long> yv[1069];
	pair<long long,long long> tmp;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		pr[make_pair(x,y)]=make_pair(x,y);
		if(!xv[x].empty())
		{
			pr[fnd(make_pair(x,y))]=fnd(make_pair(x,xv[x][0]));
		}
		if(!yv[y].empty())
		{
			pr[fnd(make_pair(x,y))]=fnd(make_pair(yv[y][0],y));
		}
		if(xv[x].empty()||yv[y].empty())
		{
			xv[x].push_back(y);
			yv[y].push_back(x);
		}
	}
	for(i=1;i<=1000;i++)
	{
		sz=xv[i].size();
		for(j=0;j<sz;j++)
		{
			tmp=fnd(make_pair(i,xv[i][j]));
			if(!m[tmp])
			{
				c++;
				m[tmp]=true;
			}
		}
	}
	printf("%lld\n",c-1);
}