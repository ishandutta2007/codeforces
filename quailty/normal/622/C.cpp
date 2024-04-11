#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
struct query
{
    int l,r,v,id;
    bool operator < (const query &t)const
    {
        return r>t.r;
    }
}t[MAXN];
int a[MAXN],res[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&t[i].l,&t[i].r,&t[i].v);
        t[i].id=i;
    }
    sort(t+1,t+m+1);
    int p=n;
    for(int i=1;i<=m;i++)
    {
        while(p>=t[i].r || (p>0 && a[p]==a[t[i].r]))p--;
        if(t[i].v!=a[t[i].r])res[t[i].id]=t[i].r;
        else res[t[i].id]=(p>=t[i].l ? p : -1);
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",res[i]);
    return 0;
}