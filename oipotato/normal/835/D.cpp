#include <cstdio>
#include <cstring>
using namespace std;
const int MOD=1000173169;
int s[5010],ans[5010],pow[5010],f[5010][5010],n;
char st[5010];
int get(int l,int r)
{
	return (long long)(s[r]-(long long)s[l-1]*pow[r-l+1]%MOD+MOD)%MOD;
}
int main()
{
	scanf("%s",st+1);
	n=strlen(st+1);
	for(int i=1;i<=n;i++)
		s[i]=((long long)s[i-1]*31+st[i])%MOD;
	pow[0]=1;
	for(int i=1;i<=n;i++)
		pow[i]=(long long)pow[i-1]*31%MOD;
	for(int i=1;i<=n;i++)
	{
		int j=0;
		for(;i-j>0&&i+j<=n&&st[i-j]==st[i+j];j++)
			f[i-j][i+j]=1;
		j=0;
		for(;i-1-j>0&&i+j<=n&&st[i-1-j]==st[i+j];j++)
			f[i-j-1][i+j]=1;
	}
	for(int i=2;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			if(f[j][j+i/2-1]&&get(j,j+i/2-1)==get(j+i-i/2,j+i-1))
				f[j][j+i-1]=f[j][j+i/2-1]+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			ans[f[j][j+i-1]]++;
	for(int i=n-1;i;i--)
		ans[i]+=ans[i+1];
	for(int i=1;i<n;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	return 0;
}