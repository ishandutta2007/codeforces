#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll INF=(1LL<<60)-1;
int p[MAXN],a[MAXN];
ll mi[MAXN<<2],tag[MAXN<<2];
inline void push_up(int n)
{
    mi[n]=min(mi[n<<1],mi[n<<1|1]);
}
inline void push_down(int n)
{
    if(!tag[n])return;
    mi[n<<1]+=tag[n];
    mi[n<<1|1]+=tag[n];
    tag[n<<1]+=tag[n];
    tag[n<<1|1]+=tag[n];
    tag[n]=0;
}
void update(int ql,int qr,int v,int l,int r,int n)
{
    if(ql==l && qr==r)
    {
        mi[n]+=v;
        tag[n]+=v;
        return;
    }
    push_down(n);
    int m=(l+r)/2;
    if(qr<=m)update(ql,qr,v,l,m,n<<1);
    else if(ql>m)update(ql,qr,v,m+1,r,n<<1|1);
    else
    {
        update(ql,m,v,l,m,n<<1);
        update(m+1,qr,v,m+1,r,n<<1|1);
    }
    push_up(n);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        update(p[i],n,a[i],0,n,1);
    ll res=INF;
    for(int i=1;i<n;i++)
    {
        update(p[i],n,-a[i],0,n,1);
        update(0,p[i]-1,a[i],0,n,1);
        res=min(res,mi[1]);
    }
    return 0*printf("%lld\n",res);
}

/*
left has d numbers (0<=d<=n)

p is left
p>d left to right

p is right
p<=d right to left
*/