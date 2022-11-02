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
const int N=2010;
int n,m,U[N][N],D[N][N],L[N],R[N];
char s[N][N];
long long ans;
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%s",s[i]+1);
	rep(i,n)rep(j,m)U[i][j]=s[i][j]==s[i-1][j]?U[i-1][j]+1:1;
	for(int i=n;i;i--)rep(j,m)D[i][j]=s[i][j]==s[i+1][j]?D[i+1][j]+1:1;
	rep(i,n)
	{
		rep(j,m)L[j]=s[i][j]==s[i][j-1]?min(L[j-1]+1,min(U[i][j],D[i][j])):1;
		for(int j=m;j;j--)R[j]=s[i][j]==s[i][j+1]?min(R[j+1]+1,min(U[i][j],D[i][j])):1;
		rep(j,m)ans+=min(L[j],R[j]);
	}
	printf("%lld\n",ans);
	return 0;
}