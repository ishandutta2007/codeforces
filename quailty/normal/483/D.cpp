#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
struct node
{
    int l,r,m,v,lazy;
}s[MAXN<<2];
void push_up(int n)
{
    s[n].v=s[n<<1].v & s[n<<1|1].v;
}
void push_down(int n)
{
    if(!s[n].lazy)return;
    s[n<<1].v|=s[n].lazy;
    s[n<<1].lazy|=s[n].lazy;
    s[n<<1|1].v|=s[n].lazy;
    s[n<<1|1].lazy|=s[n].lazy;
    s[n].lazy=0;
}
void build(int l,int r,int n)
{
    int m=(l+r)>>1;
    s[n].l=l;
    s[n].r=r;
    s[n].m=m;
    s[n].v=0;
    s[n].lazy=0;
    if(r-l==1)return;
    build(l,m,n<<1);
    build(m,r,n<<1|1);
}
void update(int l,int r,int n,int k)
{
    if(s[n].l==l && s[n].r==r)
    {
        s[n].v|=k;
        s[n].lazy|=k;
        return;
    }
    push_down(n);
    if(r<=s[n].m)update(l,r,n<<1,k);
    else if(l>=s[n].m)update(l,r,n<<1|1,k);
    else
    {
        update(l,s[n].m,n<<1,k);
        update(s[n].m,r,n<<1|1,k);
    }
    push_up(n);
}
int query(int l,int r,int n)
{
    if(s[n].l==l && s[n].r==r)return s[n].v;
    push_down(n);
    if(r<=s[n].m)return query(l,r,n<<1);
    if(l>=s[n].m)return query(l,r,n<<1|1);
    return query(l,s[n].m,n<<1) & query(s[n].m,r,n<<1|1);
}
pair<pair<int,int>,int>q[100005];
int ans[100005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,n+1,1);
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&q[i].first.first,&q[i].first.second,&q[i].second);
    for(int i=0;i<m;i++)
        update(q[i].first.first,q[i].first.second+1,1,q[i].second);
    bool isok=1;
    for(int i=0;i<m;i++)
        isok&=(query(q[i].first.first,q[i].first.second+1,1)==q[i].second);
    if(!isok)printf("NO\n");
    else
    {
        printf("YES\n");
        for(int i=1;i<=n;i++)
            printf("%s%d",(i>1 ? " " : ""),query(i,i+1,1)
                   );
    }
    return 0;
}