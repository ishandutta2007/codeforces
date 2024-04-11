#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1005;
const ll INF=(1LL<<62)-1;
ll h[MAXN][MAXN],row[MAXN][MAXN];
ll mi[MAXN][MAXN],sum[MAXN][MAXN];
bool vis[MAXN][MAXN];
struct node
{
    ll x,y,c;
    bool operator < (const node &t)const
    {
        if(c==t.c)
        {
            if(x==t.x)return y<t.y;
            else return x<t.x;
        }
        else return c<t.c;
    }
}s[MAXN*MAXN],t[MAXN*MAXN];
int main()
{
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%lld",&h[i][j]);
    for(int i=1;i<=n;i++)
    {
        deque<pair<ll,int>> dq;
        for(int j=1;j<b;j++)
        {
            while(!dq.empty() && h[i][j]<=dq.back().first)dq.pop_back();
            dq.push_back(make_pair(h[i][j],j));
        }
        for(int j=1;j+b-1<=m;j++)
        {
            while(!dq.empty() && h[i][j+b-1]<=dq.back().first)dq.pop_back();
            dq.push_back(make_pair(h[i][j+b-1],j+b-1));
            while(!dq.empty() && dq.front().second<j)dq.pop_front();
            row[i][j]=(dq.empty() ? INF : dq.front().first);
        }
    }
    for(int j=1;j+b-1<=m;j++)
    {
        deque<pair<ll,int>> dq;
        for(int i=1;i<a;i++)
        {
            while(!dq.empty() && row[i][j]<=dq.back().first)dq.pop_back();
            dq.push_back(make_pair(row[i][j],i));
        }
        for(int i=1;i+a-1<=n;i++)
        {
            while(!dq.empty() && row[i+a-1][j]<=dq.back().first)dq.pop_back();
            dq.push_back(make_pair(row[i+a-1][j],i+a-1));
            while(!dq.empty() && dq.front().second<i)dq.pop_front();
            mi[i][j]=(dq.empty() ? INF : dq.front().first);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j]=h[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    int cnt=0;
    for(int i=1;i+a-1<=n;i++)
        for(int j=1;j+b-1<=m;j++)
        {
            ll t=sum[i+a-1][j+b-1]-sum[i+a-1][j-1]-sum[i-1][j+b-1]+sum[i-1][j-1];
            s[++cnt]=node{i,j,t-mi[i][j]*a*b};
        }
    sort(s+1,s+cnt+1);
    int res=0;
    for(int i=1;i<=cnt;i++)
    {
        int x=s[i].x,y=s[i].y;
        if(vis[x][y] || vis[x+a-1][y] || vis[x][y+b-1] || vis[x+a-1][y+b-1])continue;
        t[++res]=s[i];
        for(int i=x;i<=x+a-1;i++)
            for(int j=y;j<=y+b-1;j++)
                vis[i][j]=1;
    }
    printf("%d\n",res);
    for(int i=1;i<=res;i++)
        printf("%lld %lld %lld\n",t[i].x,t[i].y,t[i].c);
    return 0;
}