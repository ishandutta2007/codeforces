#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int main()
{
    int n,m,k,s;
    scanf("%d%d%d%d%d",&n,&m,&k,&a[0],&s);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=k;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=k;i++)
        scanf("%d",&d[i]);
    ll res=~0ULL>>1;
    for(int i=0;i<=m;i++)
    {
        if(b[i]>s)continue;
        int id=upper_bound(d,d+k+1,s-b[i])-d-1;
        res=min(res,1LL*a[i]*(n-c[id]));
    }
    return 0*printf("%I64d",res);
}