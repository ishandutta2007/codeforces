#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,a[3005],f[6005][3005],ft[100005],t;
char s[300005];
int main()
{
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='R')
			a[i]=0;
		else a[i]=1;
	int ct=0;
	while(1)
	{
		t++;
		for(int i=1;i<n;i++)
			if(a[i]==0&&a[i+1]==1)
				f[t][++ft[t]]=i,ct++;
		if(!ft[t])
		{
			t--;
			break;
		}
		for(int i=1;i<=ft[t];i++)
		{
			int u=f[t][i];
			a[u]^=1,a[u+1]^=1;
		}
	}
	//printf("t=%d,ct=%d\n",t,ct);
	if(k<t||k>ct)
	{
		printf("-1");
		return 0;
	}
	int rem=ct;
	for(int i=1;i<=t;i++)
	{
		if(k<=rem-ft[i]+1)
		{
			rem-=ft[i];
			printf("%d ",ft[i]);
			for(int j=1;j<=ft[i];j++)
				printf("%d ",f[i][j]);
			printf("\n");
			k--;
		}
		else
		{
			int nw=rem-k+1;
			printf("%d ",nw);
			for(int j=1;j<=nw;j++)
				printf("%d ",f[i][j]);
			printf("\n");
			for(int j=nw+1;j<=ft[i];j++)
				printf("1 %d\n",f[i][j]);
			for(int j=i+1;j<=t;j++)
			{
				for(int k=1;k<=ft[j];k++)
					printf("1 %d\n",f[j][k]);
			}
			return 0;
		}
	}
	return 0;
}