#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
const int N=1010;
int fa[N<<1],a[N][N],n;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool can(int x,int y,int typ)
{
    if(find(2*x)==find(2*y-(!typ)))return 0;
    fa[find(2*x-1)]=find(2*y-(!typ));
    fa[find(2*x)]=find(2*y-typ);
    return 1;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n);
        rep(i,n)rep(j,n)scanf("%d",&a[i][j]);
        rep(i,n*2)fa[i]=i;
        rep(i,n)for(int j=i+1;j<=n;j++)
        {
            if(a[i][j]==a[j][i])continue;
            if(a[i][j]>a[j][i])
            {
                if(can(i,j,1))swap(a[i][j],a[j][i]);
            }
            else
            {
                if(!can(i,j,0))swap(a[i][j],a[j][i]);
            }
        }
        rep(i,n)rep(j,n)printf("%d%c",a[i][j]," \n"[j==n]);
    }
    return 0;
}