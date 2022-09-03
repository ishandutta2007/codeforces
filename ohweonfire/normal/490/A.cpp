#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=5005;
vector<int > st[3];
int t[maxn],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",t+i);
		st[t[i]-1].push_back(i);
	}
	int id=min(st[0].size(),min(st[1].size(),st[2].size()));
	printf("%d\n",id);
	for(int i=0;i<id;i++)printf("%d %d %d\n",st[0][i],st[1][i],st[2][i]);
	return 0;
}