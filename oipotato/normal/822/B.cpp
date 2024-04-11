#include<cstdio>
using namespace std;
int ans,tans,n,m,ansp[1010],tansp[1010];
char s[1010],t[1010];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	scanf("%s",t+1);
	ans=n+1;
	for(int i=1;i<=m-n+1;i++)
	{
		tans=0;
		for(int j=1;j<=n;j++)
		if(s[j]!=t[i+j-1])
		tansp[++tans]=j;
		if(tans<ans)
		{
			ans=tans;
			for(int j=1;j<=tans;j++)ansp[j]=tansp[j];
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<ans;i++)printf("%d ",ansp[i]);
	if(ans)printf("%d",ansp[ans]);
	return 0;
}