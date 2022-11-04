#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const int BLK=355;
ll t[MAXN],l[MAXN],r[MAXN];
ll a[MAXN<<1],cl[MAXN<<1],cr[MAXN<<1],res[MAXN];
struct query
{
    int l,r,id;
    bool operator < (const query &t)const
    {
        return (l/BLK==t.l/BLK ? r<t.r : l/BLK<t.l/BLK);
    }
}que[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&t[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(t[i]==2)a[i]=-a[i];
        a[i]+=a[i-1];
    }
    for(int i=0;i<=n;i++)
        l[i]=a[i+n+1]=a[i]+k,r[i]=a[i];
    sort(a,a+2*n+2);
    for(int i=0;i<=n;i++)
    {
        l[i]=lower_bound(a,a+2*n+2,l[i])-a;
        r[i]=lower_bound(a,a+2*n+2,r[i])-a;
    }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&que[i].l,&que[i].r);
        que[i].id=i;
    }
    sort(que+1,que+q+1);
    int ql=1,qr=0;
    ll tot=0;
    for(int i=1;i<=q;i++)
    {
        while(qr<que[i].r)qr++,cl[l[qr-1]]++,cr[r[qr]]++,tot+=cl[r[qr]];
        while(ql>que[i].l)ql--,cl[l[ql-1]]++,cr[r[ql]]++,tot+=cr[l[ql-1]];
        while(qr>que[i].r)tot-=cl[r[qr]],cl[l[qr-1]]--,cr[r[qr]]--,qr--;
        while(ql<que[i].l)tot-=cr[l[ql-1]],cl[l[ql-1]]--,cr[r[ql]]--,ql++;
        res[que[i].id]=tot;
    }
    for(int i=1;i<=q;i++)
        printf("%lld\n",res[i]);
    return 0;
}