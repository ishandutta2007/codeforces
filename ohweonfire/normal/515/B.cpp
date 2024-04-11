#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
unordered_set<int> happyb,happyg;
int hb,hg,n,m;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d",&hb);
	while(hb--)
	{
		int t;
		scanf("%d",&t);
		happyb.insert(t);
	}
	scanf("%d",&hg);
	while(hg--)
	{
		int t;
		scanf("%d",&t);
		happyg.insert(t);
	}
	for(int i=0;i<n*m*(n+m);i++)
	{
		int x=i%n,y=i%m;
		if(happyb.count(x)||happyg.count(y))
		{
			happyb.insert(x);
			happyg.insert(y);
		}
	}
	if(happyb.size()==n&&happyg.size()==m)
		puts("YES");
	else
		puts("NO");
	return 0;
}