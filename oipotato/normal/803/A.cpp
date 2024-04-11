#include<cstdio>
#include<cstdlib>
using namespace std;
bool cov[110][110];
int n,k;
void print_ans()
{
	for(int i=1;i<=n&&k>0;i++)
	if(!cov[i][i])
	{
		k--;
		cov[i][i]=1;
	}
	if(k>0)
	{
		printf("-1");
		exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)printf("%d ",cov[i][j]);
		printf("%d\n",cov[i][n]);
	}
	exit(0);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(!cov[i][j])
	if(i==j)
	{
		if(k>=1)
		{
			k--;
			cov[i][j]=1;
		}
		else print_ans();
	}
	else
	{
		if(k>=2)
		{
			cov[i][j]=cov[j][i]=1;
			k-=2;
		}
		else print_ans();
	}
	print_ans();
	return 0;
}