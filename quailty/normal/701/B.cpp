#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
bool visx[MAXN],visy[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int cntx=n,cnty=n;
    ll res=1LL*n*n;
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(!visx[x])res-=cnty,cntx--,visx[x]=1;
        if(!visy[y])res-=cntx,cnty--,visy[y]=1;
        printf("%I64d\n",res);
    }
    return 0;
}