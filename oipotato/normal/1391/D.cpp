#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int a[1000010][4],f[1000010][1<<3],n,m;
char s[1000010];
int cal(int msk,int a[])
{
	int t=0;
	for(int j=0;j<m;j++)if(((msk>>j)&1)!=a[j])t++;
	return t;
}
bool ok(int m1,int m2)
{
	m1^=m2;
	m1^=m1>>1;
	if(m==3)return (m1&3)==3;else return (m1&1);
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n<2||m<2){puts("0");return 0;}
	if(n>=4&&m>=4){puts("-1");return 0;}
	rep(i,n)
	{
		scanf("%s",s+1);
		if(n<m)rep(j,m)a[j][i-1]=s[j]-'0';
		else rep(j,m)a[i][j-1]=s[j]-'0';
	}
	if(n<m)swap(n,m);
	rep(i,n)rep(j,(1<<m))f[i][j-1]=n*m;
	rep(i,(1<<m))f[1][i-1]=cal(i-1,a[1]);
	for(int i=2;i<=n;i++)
	rep(j,(1<<m))
	rep(k,(1<<m))
	if(ok(j-1,k-1))
	f[i][k-1]=min(f[i][k-1],f[i-1][j-1]+cal(k-1,a[i]));
	int ans=n*m;
	rep(i,(1<<m))ans=min(ans,f[n][i-1]);
	printf("%d\n",ans);
	return 0;
}