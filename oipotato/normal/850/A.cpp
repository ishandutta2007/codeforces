#include <cstdio>
#include <cstring>
using namespace std;
int a[1010][5],n,ans;
bool v[1010];
int dot(int i,int j,int k)
{
	int tans=0;
	for(int p=0;p<5;p++)
		tans+=(a[j][p]-a[i][p])*(a[k][p]-a[i][p]);
	return tans;
}
int main()
{
	scanf("%d",&n);
	if(n>200)
		printf("0\n");
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=0;j<5;j++)
				scanf("%d",&a[i][j]);
		memset(v,1,sizeof(v));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					if(k!=j&&i!=j&&k!=j&&dot(i,j,k)>0)
						v[i]=0;
		for(int i=1;i<=n;i++)
			if(v[i])
				ans++;
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			if(v[i])
				printf("%d\n",i);
	}
	return 0;
}