#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m,a[1000005];
#define F(x,y) (x-1)*m+y
inline int solve(int x,int y)
{
	return max(x-1,n-x)+max(y-1,m-y);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				a[F(i,j)]=solve(i,j);
			}
		sort(a+1,a+n*m+1);
		for(int i=1;i<=n*m;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
}