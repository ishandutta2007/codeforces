#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
pair<int,int> lap[100002],top[100002];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&lap[i].first,&lap[i].second);
		top[i].first=lap[i].second;
		top[i].second=lap[i].first;
	}
	sort(lap,lap+n);
	sort(top,top+n);
	for(int i=0;i<n;++i)
		if(top[i].first!=lap[i].second||top[i].second!=lap[i].first)
		{
			puts("Happy Alex");
			return 0;
		}
	puts("Poor Alex");
	return 0;
}