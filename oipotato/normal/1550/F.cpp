#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=200010;
struct Data
{
    int a,b,k,del;
    bool operator<(const Data&a)const{return k>a.k;}
};
struct Query
{
    int id,x,k;
    void scan(int _id){id=_id;scanf("%d%d",&x,&k);}
    bool operator<(const Query&a)const{return k<a.k;}
}que[N];
priority_queue<Data>hp;
int n,q,s,d,a[N],fa[N],ans[N];
bool vis[2][N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
    scanf("%d%d%d%d",&n,&q,&s,&d);
    rep(i,n)scanf("%d",&a[i]);
    rep(i,q)que[i].scan(i);
    sort(que+1,que+q+1);
    rep(i,n)
    {
        int x=lower_bound(a+1,a+n+1,a[i]-d)-a;
        if(x<i)hp.push({i,x,abs(d-abs(a[i]-a[x])),1});
        x=upper_bound(a+1,a+n+1,a[i]-d)-a-1;
        if(x)hp.push({i,x,abs(d-abs(a[i]-a[x])),-1});
        x=lower_bound(a+1,a+n+1,a[i]+d)-a;
        if(x<=n)hp.push({i,x,abs(d-abs(a[i]-a[x])),1});
        x=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
        if(x>i)hp.push({i,x,abs(d-abs(a[i]-a[x])),-1});
    }
    rep(i,n)fa[i]=i;
    int now=1;
    for(;!hp.empty();hp.pop())
    {
        auto u=hp.top();
        int a=u.a,b=u.b,k=u.k,del=u.del,typ=del>0;
        for(;now<=q&&que[now].k<k;ans[que[now].id]=find(s)==find(que[now].x),now++);
        fa[find(a)]=find(b);
        if(vis[typ][b])continue;
        vis[typ][b]=1;
        b+=del;
        if(!b||b==a||b>n)continue;
        hp.push({a,b,abs(d-abs(::a[a]-::a[b])),del});
    }
    for(;now<=q;ans[que[now].id]=find(s)==find(que[now].x),now++);
    rep(i,q)puts(ans[i]?"Yes":"No");
    return 0;
}