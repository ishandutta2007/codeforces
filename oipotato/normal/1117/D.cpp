#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int MOD=1000000007;
int m;
long long n;
struct Matrix
{
	int a[110][110];
	friend Matrix operator*(const Matrix&a,const Matrix&b)
	{
		Matrix c;memset(c.a,0,sizeof(c.a));
		rep(i,m+1)rep(k,m+1)rep(j,m+1)c.a[i][j]=(c.a[i][j]+1ll*a.a[i][k]*b.a[k][j])%MOD;
		return c;
	}
}ans,tmp;
int main()
{
	scanf("%lld%d",&n,&m);
	rep(i,m)tmp.a[i][i+1]=1;
	tmp.a[m+1][1]=tmp.a[m+1][m+1]=1;
	tmp.a[m][1]=1;
	rep(i,m+1)ans.a[i][i]=1;
	for(;n;n>>=1,tmp=tmp*tmp)if(n&1)ans=ans*tmp;
	printf("%d\n",(ans.a[m+1][m+1]+ans.a[m+1][m])%MOD);
	return 0;
}