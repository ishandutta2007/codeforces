#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=1E9+7;
int n,L,m,x,ANS,b[1000010],c[1000010];
struct Matrix
{
	int a[110][110];
	friend Matrix operator *(Matrix a,Matrix b)
	{
		Matrix c;
		memset(c.a,0,sizeof(c.a));
		for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
		for(int k=0;k<m;k++)
		c.a[i][j]=(c.a[i][j]+1ll*a.a[i][k]*b.a[k][j])%MOD;
		return c;
	}
}A,B,ans,tmp,tans;
Matrix quick_pow(Matrix B,int n)
{
	tmp=B;
	memset(tans.a,0,sizeof(tans.a));
	for(int i=0;i<m;i++)tans.a[i][i]=1;
	for(;n;n>>=1)
	{
		if(n&1)tans=tans*tmp;
		tmp=tmp*tmp;
	}
	return tans;
}
void print(Matrix A)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)printf("%d ",A.a[i][j]);
		puts("");
	}
	puts("");
}
int main()
{
	scanf("%d%d%d",&n,&L,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(int j=0;j<m;j++)A.a[j][(j+x)%m]++;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(int j=0;j<m;j++)B.a[j][(j+x)%m]++;
		b[i]=x;
	}
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	ans=A*quick_pow(B,L-2);
	ANS=0;
	for(int i=1;i<=n;i++)
	ANS=(ANS+ans.a[0][(m-(b[i]+c[i])%m)%m])%MOD;
	printf("%d\n",ANS);
	return 0;
}