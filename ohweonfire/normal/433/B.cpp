#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100005;
int arr[maxn],n,m,x,y,z;
long long prev[3][maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",arr+i);
	for(int i=1;i<3;i++)
	{
		for(int j=1;j<=n;j++)
			prev[i][j]=prev[i][j-1]+arr[j];
		sort(arr+1,arr+n+1);
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d%d",&x,&y,&z);
		printf("%I64d\n",prev[x][z]-prev[x][y-1]);
	}
	return 0;
}