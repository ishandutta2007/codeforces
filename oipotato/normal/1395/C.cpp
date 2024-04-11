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
int a[210],b[210],f[210][1<<9],n,m;
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,m)scanf("%d",&b[i]);
	f[0][0]=1;
	rep(i,n)
	rep(msk,(1<<9))
	if(f[i-1][msk-1])
	rep(j,m)
	f[i][(msk-1)|(a[i]&b[j])]=1;
	rep(i,(1<<9))if(f[n][i-1]){printf("%d\n",i-1);return 0;}
	return 0;
}