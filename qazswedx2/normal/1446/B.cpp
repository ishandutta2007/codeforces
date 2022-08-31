#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,f[5005][5005],ans=0;
char a[100005],b[100005];
int main()
{
	scanf("%d%d%s%s",&n,&m,a+1,b+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(0,max(f[i-1][j],f[i][j-1])-1);
			if(a[i]==b[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+2);
			ans=max(ans,f[i][j]);
		}
	printf("%d",ans);
	return 0;
}