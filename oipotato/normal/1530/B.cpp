#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[30][30];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,m;scanf("%d%d",&n,&m);
        rep(i,n)rep(j,m)a[i][j]=0;
        a[1][1]=1;
        for(int i=3;i<=m;i+=2)a[1][i]=1;
        for(int i=3;i<=n;i+=2)a[i][1]=a[i][m]=1;
        for(int i=3;i<=m-2;i+=2)a[n][i]=1;
        rep(i,n){rep(j,m)printf("%d",a[i][j]);puts("");}
    }
    return 0;
}