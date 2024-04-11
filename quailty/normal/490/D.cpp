#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const ll INF=(1LL<<60)-1;
void bfs(ll st,map<ll,ll>&dis)
{
    dis.clear();
    dis[st]=0;
    queue<ll>q;
    q.push(st);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        if(u%2==0 && (dis.find(u/2)==dis.end() || dis[u/2]>dis[u]+1))
        {
            q.push(u/2);
            dis[u/2]=dis[u]+1;
        }
        if(u%3==0 && (dis.find(u/3*2)==dis.end() || dis[u/3*2]>dis[u]+1))
        {
            q.push(u/3*2);
            dis[u/3*2]=dis[u]+1;
        }
    }
}
map<ll,ll>mp[5];
int main()
{
    ll a[2],b[2];
    for(int i=0;i<2;i++)
        scanf("%I64d%I64d",&a[i],&b[i]);
    bfs(a[0],mp[0]);
    bfs(b[0],mp[1]);
    bfs(a[1],mp[2]);
    bfs(b[1],mp[3]);
    for(auto itra=mp[0].begin();itra!=mp[0].end();itra++)
        for(auto itrb=mp[1].begin();itrb!=mp[1].end();itrb++)
        {
            ll s=itra->first * itrb->first,t=itra->second + itrb->second;
            if(mp[4].find(s)==mp[4].end())mp[4][s]=INF;
            mp[4][s]=min(mp[4][s],t);
        }
    ll mi=INF,area=-1;
    for(auto itra=mp[2].begin();itra!=mp[2].end();itra++)
        for(auto itrb=mp[3].begin();itrb!=mp[3].end();itrb++)
        {
            ll s=itra->first * itrb->first,t=itra->second + itrb->second;
            if(mp[4].find(s)!=mp[4].end() && mi>mp[4][s]+t)
                mi=mp[4][s]+t,area=s;
        }
    if(mi==INF)return 0*printf("-1\n");
    printf("%I64d\n",mi);
    for(auto itra=mp[0].begin();itra!=mp[0].end();itra++)
        for(auto itrb=mp[1].begin();itrb!=mp[1].end();itrb++)
        {
            ll s=itra->first * itrb->first;
            if(s==area)
            {
                printf("%I64d %I64d\n",itra->first,itrb->first);
                goto ok1;
            }
        }
    ok1:
    for(auto itra=mp[2].begin();itra!=mp[2].end();itra++)
        for(auto itrb=mp[3].begin();itrb!=mp[3].end();itrb++)
        {
            ll s=itra->first * itrb->first;
            if(s==area)
            {
                printf("%I64d %I64d\n",itra->first,itrb->first);
                goto ok2;
            }
        }
    ok2:
    return 0;
}