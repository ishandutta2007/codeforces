#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int n;
ll A,cf,cm,m;
ll a[MAXN];
struct node
{
    ll v;
    int id;
    bool operator < (const node &t)const
    {
        return v<t.v;
    }
} b[MAXN];
ll pre[MAXN],res[MAXN];
int main()
{
    scanf("%d%I64d%I64d%I64d%I64d",&n,&A,&cf,&cm,&m);
    for(int i=0; i<n; i++)
        scanf("%I64d",&a[i]);
    for(int i=0; i<n; i++)
    {
        b[i].v=a[i];
        b[i].id=i;
    }
    sort(b,b+n);
    b[n].v=A;
    ll sum=0;
    for(int i=0;i<=n;i++)
    {
        pre[i]=i*b[i].v-sum;
        sum+=b[i].v;
    }
    sum=0;
    ll ans=0,loc=n;
    for(int i=n;i>0;i--)
    {
        ll rem=m-((n-i)*A-sum);
        int w=upper_bound(pre,pre+i,rem)-pre;
        if(w==0)break;
        ll now=(n-i)*cf+min(A,(b[w-1].v+(rem-pre[w-1])/w))*cm;
        if(now>ans)
        {
            ans=now;
            loc=i;
        }
        sum+=b[i-1].v;
    }
    if(m-(n*A-sum)>=0)
    {
        ans=n*cf+A*cm;
        loc=0;
    }
    for(int i=loc;i<n;i++)
    {
        m-=A-b[i].v;
        b[i].v=A;
    }
    int w=upper_bound(pre,pre+loc,m)-pre;
    for(int i=0;i<w;i++)
        b[i].v=min(A,b[w-1].v+(m-pre[w-1])/w);
    for(int i=0;i<n;i++)
        res[b[i].id]=b[i].v;
    printf("%I64d\n",ans);
    for(int i=0;i<n;i++)
        printf("%s%I64d",(i>0 ? " " : ""),res[i]);
    return 0;
}