// Thanks to robs77 for this template
/***********HEADER***************/
#include <bits/stdc++.h>

/***********MACROS***************/
//#define int long long
#define inf 100000000000000000 
#define ll  long long 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second     
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define modLim (int)(pow(10,9)+7)
//#define mod 1000000007
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
const int N=(1<<17)+10;
struct node
{
    int l,r,x;
}t[N<<2];
int a[N];
/*********FUNCTIONS**************/
void build(int l,int r,int x,int d)
{
    t[x].l=l;
    t[x].r=r;
    if(l==r){
        t[x].x=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,x<<1,-d);
    build(mid+1,r,x<<1|1,-d);
    if(d==1) t[x].x=t[x<<1].x^t[x<<1|1].x;
    else t[x].x=t[x<<1].x|t[x<<1|1].x;
}
int query(int l,int r,int x)
{
    if(t[x].l==l&&t[x].r==r) return t[x].x;
    int mid=(t[x].l+t[x].r)>>1;
    if(r<=mid) return query(l,r,x<<1);
    else if(l>mid) return query(l,r,x<<1|1);
    else return query(l,mid,x<<1)^query(mid+1,r,x<<1|1);
}
void update(int x,int v,int o,int d)
{
    if(t[o].l==t[o].r && t[o].l==x){
        t[o].x=v;
        return ;
    }
    int mid=(t[o].l+t[o].r)>>1;
    if(x<=mid) update(x,v,o<<1,-d);
    else update(x,v,o<<1|1,-d);
    if(d==1) t[o].x=t[o<<1].x^t[o<<1|1].x;
    else t[o].x=t[o<<1].x|t[o<<1|1].x;
}
/***********MAIN**************/
int main(){
    int n,m;
    int p,b,d,num;
    while(~scanf("%d%d",&n,&m)){
        num=1<<n;
        for(int i=1;i<=num;++i) scanf("%d",&a[i]);
        if(n&1) d=-1;
        else d=1;
        build(1,num,1,d);
        while(m--){
            scanf("%d%d",&p,&b);
            update(p,b,1,d);
            printf("%d\n",query(1,num,1));
        }
    }
    return 0;
     
}