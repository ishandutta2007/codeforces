#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1<<19;
int cnt[MAXN+5],now=0;
int count(int l,int r)
{
    return cnt[r]-(l>0 ? cnt[l-1] : 0);
}
int query(int l,int r,int d)
{
    if(d<0)return l;
    int tl=l,tr=(l+r)/2;
    if(now>>d&1)tl^=(1<<d),tr^=(1<<d);
    if(count(tl,tr)<tr-tl+1)return query(tl,tr,d-1);
    return query(tl^(1<<d),tr^(1<<d),d-1);
}
int main()
{
//    printf("%d\n",MAXN);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        cnt[a]=1;
    }
    for(int i=1;i<MAXN;i++)
        cnt[i]+=cnt[i-1];
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        now^=x;
        printf("%d\n",query(0,MAXN-1,18)^now);
    }
    return 0;
}