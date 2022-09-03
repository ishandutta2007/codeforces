#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=1002;
int begin[maxn],end[maxn],n,cnt;
vector<int> ans;
bool use[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",begin+i,end+i);
		if(begin[i]>end[i])
			swap(begin[i],end[i]);
	}
	for(int i=1;i<n;i++)
		for(int j=1;j<=n-i;j++)
			if(end[j]>end[j+1])
			{
				swap(end[j],end[j+1]);
				swap(begin[j],begin[j+1]);
			}
	for(int i=1;i<=n;i++)
		if(!use[i])
		{
			for(int j=i;j<=n;j++)
				if(begin[j]<=end[i]&&end[j]>=end[i])
					use[j]|=true;
			cnt++;
			ans.push_back(end[i]);
		}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
		printf("%d ",ans[i]);
	return 0;
}