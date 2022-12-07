#include<bits/stdc++.h>
using namespace std;
int num[1000010];
double d[1000010];
typedef pair<double,int> pii;
pii st[1000010];
int o=0;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		d[i]=(double)num[i];
	}
	for(int i=1;i<=n;i++)
	{
		o++;
		st[o]=make_pair(d[i],1);
		while(o>=2)
		{
			if(st[o].first<st[o-1].first)
			{
				pii p;
				p.second=st[o].second+st[o-1].second;
				p.first=(st[o].first*st[o].second+st[o-1].first*st[o-1].second)/p.second;
				st[o-1]=p;
				o--;
			}
			else
				break;
		}
	}
	for(int i=1;i<=o;i++)
		for(int j=1;j<=st[i].second;j++)
			printf("%.12f\n",st[i].first);
}