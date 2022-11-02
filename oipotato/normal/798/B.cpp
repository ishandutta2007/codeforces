#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
char st[55][55];
int len,ans,n;
bool ok[55][55];
int main()
{
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)scanf("%s",st[i]);
	len=strlen(st[1]);
	for(int i=2;i<=n;i++)
	if(len!=strlen(st[i]))
	{
		printf("-1");
		exit(0);
	}
	for(int i=2;i<=n;i++)
	{
		bool flag1=0;
		for(int j=0;j<len;j++)
		{
			bool flag2=1;
			for(int k=0,p=j;k<len;k++,p=(p+1)%len)
			if(st[1][k]!=st[i][p])
			{
				flag2=0;
				break;
			}
			if(flag2)
			{
				ok[i][j]=1;
				flag1=1;
			}
		}
		if(!flag1)
		{
			printf("-1");
			exit(0);
		}
	}
	ans=n*len;
	for(int i=0;i<len;i++)
	{
		int tans=i;
		for(int j=2;j<=n;j++)
		{
			int tans2=2*len;
			for(int k=0;k<len;k++)
			if(ok[j][k])
			tans2=min(tans2,(i+k)%len);
			tans+=tans2;
		}
		ans=min(ans,tans);
	}
	printf("%d",ans);
	return 0;
}