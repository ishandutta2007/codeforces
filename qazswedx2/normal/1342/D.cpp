#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,a[1000005],b[1000005],sz[200005];
vector<int> tans[200005];
bool cmp(const int x,const int y)
{
	return x>y;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	for(int i=n;i>0;i--)
	{
		int nw=upper_bound(sz+1,sz+n+1,b[a[i]],cmp)-sz;
		sz[nw]++;
		tans[nw].push_back(a[i]);
	}
	int ct=0;
	for(int i=1;i<=n+1;i++)
	{
		if(!sz[i])
		{
			ct=i-1;
			break;
		}
	}
	printf("%d\n",ct);
	for(int i=1;i<=ct;i++)
	{
		printf("%d ",sz[i]);
		for(int j=0;j<sz[i];j++)
			printf("%d ",tans[i][j]);
		printf("\n");
	}
	return 0;
}