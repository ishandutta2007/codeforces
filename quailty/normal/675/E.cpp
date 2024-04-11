#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<62)-1;
struct node
{
    int l,r,m;
    ll v;
}s[MAXN<<2];
void push_up(int n)
{
    s[n].v=min(s[n<<1].v,s[n<<1|1].v);
}
void build(int l,int r,int n)
{
    int m=(l+r)>>1;
    s[n].l=l;
    s[n].r=r;
    s[n].m=m;
    s[n].v=INF;
    if(r-l==1)return;
    build(l,m,n<<1);
    build(m,r,n<<1|1);
    push_up(n);
}
void update(int p,ll v,int n)
{
    if(s[n].l==p && s[n].r==p+1)
    {
        s[n].v=min(s[n].v,v);
        return;
    }
    if(p<s[n].m)update(p,v,n<<1);
    else update(p,v,n<<1|1);
    push_up(n);
}
ll query(int l,int r,int n)
{
    if(s[n].l==l && s[n].r==r)return s[n].v;
    if(r<=s[n].m)return query(l,r,n<<1);
    if(l>=s[n].m)return query(l,r,n<<1|1);
    return min(query(l,s[n].m,n<<1),query(s[n].m,r,n<<1|1));
}
int a[MAXN];
ll dp[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
        scanf("%d",&a[i]);
    dp[n]=0;
    build(1,n+1,1);
    update(n,n,1);
    for(int i=n-1;i>=1;i--)
        update(i,(dp[i]=query(i+1,a[i]+1,1)-a[i]+n-i)+i,1);
    long long res=0;
    for(int i=1;i<=n-1;i++)
        res+=dp[i];
    printf("%I64d",res);
    return 0;
}