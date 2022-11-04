#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const int L=1,R=200000;
int cnt[MAXN<<2],tag[MAXN<<2];
ll sum[MAXN<<2];
void push_down(int n)
{
    if(!tag[n])return;
    sum[n<<1]+=1LL*cnt[n<<1]*tag[n];
    sum[n<<1|1]+=1LL*cnt[n<<1|1]*tag[n];
    tag[n<<1]+=tag[n];
    tag[n<<1|1]+=tag[n];
    tag[n]=0;
}
void push_up(int n)
{
    cnt[n]=cnt[n<<1]+cnt[n<<1|1];
    sum[n]=sum[n<<1]+sum[n<<1|1];
}
void update_cnt(int p,int c,int s,int l,int r,int n)
{
    if(l==r)
    {
        cnt[n]=c,sum[n]=s;
        return;
    }
    push_down(n);
    int m=(l+r)/2;
    if(p<=m)update_cnt(p,c,s,l,m,n<<1);
    else update_cnt(p,c,s,m+1,r,n<<1|1);
    push_up(n);
}
int query_cnt(int ql,int qr,int l,int r,int n)
{
    if(ql==l && qr==r)return cnt[n];
    push_down(n);
    int m=(l+r)/2;
    if(qr<=m)return query_cnt(ql,qr,l,m,n<<1);
    if(ql>m)return query_cnt(ql,qr,m+1,r,n<<1|1);
    return query_cnt(ql,m,l,m,n<<1)+query_cnt(m+1,qr,m+1,r,n<<1|1);
}
void update_sum(int ql,int qr,int v,int l,int r,int n)
{
    if(ql==l && qr==r)
    {
        sum[n]+=v*cnt[n],tag[n]+=v;
        return;
    }
    push_down(n);
    int m=(l+r)/2;
    if(qr<=m)update_sum(ql,qr,v,l,m,n<<1);
    else if(ql>m)update_sum(ql,qr,v,m+1,r,n<<1|1);
    else
    {
        update_sum(ql,m,v,l,m,n<<1);
        update_sum(m+1,qr,v,m+1,r,n<<1|1);
    }
    push_up(n);
}
ll query_sum(int ql,int qr,int l,int r,int n)
{
    if(ql==l && qr==r)return sum[n];
    push_down(n);
    int m=(l+r)/2;
    if(qr<=m)return query_sum(ql,qr,l,m,n<<1);
    if(ql>m)return query_sum(ql,qr,m+1,r,n<<1|1);
    return query_sum(ql,m,l,m,n<<1)+query_sum(m+1,qr,m+1,r,n<<1|1);
}
int c[MAXN];
int main()
{
    int q,d;
    scanf("%d%d",&q,&d);
    ll res=0;
    for(int i=1;i<=q;i++)
    {
        int a;
        scanf("%d",&a);
        if(c[a]==0) // add
        {
            int act=query_cnt(max(L,a-d),a,L,R,1);
            res+=1LL*act*(act-1)/2+query_sum(a,min(R,a+d),L,R,1);
            update_sum(a,min(R,a+d),1,L,R,1);
            update_cnt(a,1,act,L,R,1);
            c[a]=1;
        }
        else // del
        {
            c[a]=0;
            update_cnt(a,0,0,L,R,1);
            update_sum(a,min(R,a+d),-1,L,R,1);
            int act=query_cnt(max(L,a-d),a,L,R,1);
            res-=1LL*act*(act-1)/2+query_sum(a,min(R,a+d),L,R,1);
        }
        printf("%lld\n",res);
    }
    return 0;
}