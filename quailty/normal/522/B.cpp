#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int w[200005],h[200005];
struct node
{
    int l,r,m,h;
}s[200005<<2];
void build(int l,int r,int num)
{
    int m=(l+r)>>1;
    s[num].l=l;
    s[num].r=r;
    s[num].m=m;
    if(r-l==1)
    {
        s[num].h=h[l];
    }
    else
    {
        build(l,m,num<<1);
        build(m,r,num<<1|1);
        s[num].h=max(s[num<<1].h,s[num<<1|1].h);
    }
}
int query(int l,int r,int num)
{
    if(l==r)return 0;
    if(s[num].l==l && s[num].r==r)
    {
        return s[num].h;
    }
    if(r<=s[num].m)
    {
        return query(l,r,num<<1);
    }
    if(l>=s[num].m)
    {
        return query(l,r,num<<1|1);
    }
    return max(query(l,s[num].m,num<<1),query(s[num].m,r,num<<1|1));
}
int main()
{
    int n;
    scanf("%d",&n);
    int wsum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&w[i],&h[i]);
        wsum+=w[i];
    }
    build(1,n+1,1);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",(wsum-w[i])*max(query(1,i,1),query(i+1,n+1,1)));
    }
    return 0;
}