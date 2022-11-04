#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int a[MAXN],b[MAXN],p[MAXN];
int seg[MAXN],idx[MAXN];
ll pre[MAXN],val[MAXN<<2],lz[MAXN<<2];
void push_up(int n)
{
    val[n]=min(val[n<<1],val[n<<1|1]);
}
void push_down(int n)
{
    if(!lz[n])return;
    val[n<<1]+=lz[n];
    val[n<<1|1]+=lz[n];
    lz[n<<1]+=lz[n];
    lz[n<<1|1]+=lz[n];
    lz[n]=0;
}
void build(int l,int r,int n)
{
    if(l==r)
    {
        val[n]=pre[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
    push_up(n);
}
void update(int ql,int qr,int v,int l,int r,int n)
{
    if(ql==l && qr==r)
    {
        val[n]+=v;
        lz[n]+=v;
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
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&p[i]);
    int cnt=0;
    for(int i=n;i>=1;i--)
    {
        if(a[i]>seg[cnt])seg[++cnt]=a[i];
        pre[cnt]+=a[i];
    }
    reverse(seg+1,seg+cnt+1);
//    for(int i=1;i<=cnt;i++)
//        printf("%d ",seg[i]);
//    printf("\n");
    reverse(pre+1,pre+cnt+1);
    for(int i=1;i<=cnt;i++)
        pre[i]+=pre[i-1];
    for(int i=1;i<=m;i++)
        b[i]=upper_bound(seg+1,seg+cnt+1,b[i],greater<int>())-seg-1;
//    for(int i=1;i<=m;i++)
//        printf("%d ",b[i]);
//    printf("\n");
    for(int i=1;i<=m;i++)
        idx[i]=i;
    sort(idx+1,idx+m+1,[](int x,int y){return p[x]<p[y];});
    build(1,cnt,1);
    int res=0;
    for(int ii=1;ii<=m;ii++)
    {
        int i=idx[ii];
        if(!b[i])continue;
        update(b[i],cnt,-p[i],1,cnt,1);
        if(val[1]<0)update(b[i],cnt,p[i],1,cnt,1);
        else res++;
    }
    printf("%d\n",res);
    return 0;
}