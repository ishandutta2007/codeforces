#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n;
char s[100005],s2[5005][5005];
bool cmp(int x,int y)
{
	for(int i=1;i<=n;i++)
		if(s2[x][i]!=s2[y][i])
			return s2[x][i]<s2[y][i];
	return x<y;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)
		{
			int ct=0;
			for(int j=i;j<=n;j++)
				s2[i][++ct]=s[j];
			if((n-i+1)%2==0)
			{
				for(int j=1;j<i;j++)
					s2[i][++ct]=s[j];
			}
			else
			{
				for(int j=i-1;j;j--)
					s2[i][++ct]=s[j];
			}
			s2[i][++ct]=0;
		}
		int ans=1;
		for(int i=2;i<=n;i++)
			if(cmp(i,ans))
				ans=i;
		printf("%s\n%d\n",s2[ans]+1,ans);
	}
	return 0;
}