#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const char str[15][15]={"1110111","0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int n,k,f[2005][2005],cnt[1005],b[15],a[200005],c[100005][11];
char s[105];
int getans(const char *s)
{
	int ans=0;
	for(int j=0;j<7;j++)
		ans+=((s[j]-'0')<<(6-j));
	return ans;
}
int main()
{
	for(int i=0;i<=9;i++)
		b[i]=getans(str[i]);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		a[i]=getans(s);
	}
	for(int i=1;i<(1<<7);i++)
		cnt[i]=cnt[i/2]+i%2;
	for(int i=1;i<=n;i++)
		for(int j=0;j<10;j++)
			if((a[i]&b[j])!=a[i])
				c[i][j]=-1;
			else c[i][j]=cnt[a[i]^b[j]];
	f[n+1][0]=1;
	for(int i=n;i>0;i--)
		for(int l=0;l<10;l++)
			if(c[i][l]!=-1)
				for(int j=c[i][l];j<=k;j++)
					f[i][j]|=f[i+1][j-c[i][l]];
	if(!f[1][k])
	{
		printf("-1");
		return 0;
	}
	int nw=k;
	for(int i=1;i<=n;i++)
	{
		for(int l=9;l>=0;l--)
			if(c[i][l]!=-1&&nw>=c[i][l]&&f[i+1][nw-c[i][l]])
			{
				nw-=c[i][l];
				printf("%d",l);
				break;
			}
	}
	return 0;
}