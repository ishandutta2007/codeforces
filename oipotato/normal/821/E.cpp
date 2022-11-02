#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MOD=1000000007;
struct Matrix
{
	int len,a[20][20];
	friend Matrix operator *(Matrix a,Matrix b)
	{
		Matrix c;
		c.len=a.len;
		memset(c.a,0,sizeof(c.a));
		for(int i=1;i<=a.len;i++)
		for(int j=1;j<=a.len;j++)
		for(int k=1;k<=a.len;k++)
		c.a[i][j]=(c.a[i][j]+(long long)a.a[i][k]*b.a[k][j])%MOD;
		return c;
	}
};
long long k,a,b;
int n,c,ans[20],tans[20];
Matrix get(int c,long long n)
{
	Matrix tmp,tans;
	tans.len=tmp.len=c;
	memset(tmp.a,0,sizeof(tmp.a));
	memset(tans.a,0,sizeof(tans.a));
	for(int i=1;i<=c;i++)tans.a[i][i]=1;
	tmp.a[1][1]=tmp.a[2][1]=tmp.a[c][c]=tmp.a[c-1][c]=1;
	for(int i=2;i<c;i++)tmp.a[i-1][i]=tmp.a[i][i]=tmp.a[i+1][i]=1;
	for(;n;n>>=1)
	{
		if(n&1)tans=tans*tmp;
		tmp=tmp*tmp;
	}
	return tans;
}
int main()
{
	scanf("%d%I64d",&n,&k);
	ans[1]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d%d",&a,&b,&c);c++;
		if(i==n)b=min(b,k);
		Matrix tmp=get(c,b-a);
		for(int j=1;j<=16;j++)tans[j]=0;
		for(int j=1;j<=c;j++)
		for(int k=1;k<=c;k++)
		tans[k]=(tans[k]+(long long)ans[j]*tmp.a[j][k])%MOD;
		for(int j=1;j<=16;j++)ans[j]=tans[j];
	}
	printf("%d",ans[1]);
	return 0;
}