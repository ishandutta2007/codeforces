#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
vector<pair<int,int> > p,sw;
int a[MAXN];
bool av[MAXN];
int main()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p.push_back({a[i],i});
	}
	sort(p.begin(),p.end());
	for(int i=0;i<n;i++)
	{
		int val=p[i].first, ind=p[i].second;
		av[ind]=true;
		for(int j=n;j>ind;j--) if(av[j]) sw.push_back({ind,j});
	}
	printf("%d\n",sw.size());
	for(int i=0;i<sw.size();i++) printf("%d %d\n",sw[i].first,sw[i].second);
}