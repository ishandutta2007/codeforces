#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const int MAXN=200005;
struct seg
{
    ll l,r;
    int id;
    bool operator < (const seg &t)const
    {
        return r==t.r ? l<t.l : r<t.r;
    }
}t[MAXN];
ll l[MAXN],r[MAXN];
struct bridge
{
    ll a;
    int id;
    bridge(ll a=0,int id=0):a(a),id(id){}
    bool operator < (const bridge &t)const
    {
        return a==t.a ? id<t.id : a<t.a;
    }
};
set<bridge>s;
set<bridge>::iterator itr;
int ans[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d%I64d",&l[i],&r[i]);
    }
    for(int i=1;i<n;i++)
    {
        t[i].l=l[i+1]-r[i];
        t[i].r=r[i+1]-l[i];
        t[i].id=i;
    }
    sort(t+1,t+n);
    bridge in;
    for(int i=1;i<=m;i++)
    {
        scanf("%I64d",&in.a);
        in.id=i;
        s.insert(in);
    }
    bool isok=1;
    for(int i=1;i<n;i++)
    {
        if(s.empty())
        {
            isok=0;
            break;
        }
        itr=s.lower_bound(bridge(t[i].l,0));
        if(itr==s.end() || (*itr).a>t[i].r)
        {
            isok=0;
            break;
        }
        ans[t[i].id]=(*itr).id;
        s.erase(itr);
    }
    if(isok)
    {
        printf("Yes\n");
        for(int i=1;i<n;i++)
        {
            printf("%d ",ans[i]);
        }
    }
    else printf("No\n");
    return 0;
}