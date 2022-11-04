#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
struct monotonic_queue
{
    deque<pair<int,int> >q;
    void init()
    {
        q.clear();
    }
    int query(int t)
    {
        while(!q.empty() && q.front().second<t)q.pop_front();
        return (q.empty() ? INF : q.front().first);
    }
    void add(int v,int t)
    {
        while(!q.empty() && q.back().first>=v)q.pop_back();
        q.push_back(make_pair(v,t));
    }
}q1,q2;
int t[MAXN],dp[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    memset(dp,INF,sizeof(dp));
    dp[0]=0;
    q1.init(),q2.init();
    q1.add(dp[0],0),q2.add(dp[0],0);
    for(int i=1,p1=1,p2=1;i<=n;i++)
    {
        dp[i]=min(dp[i],dp[i-1]+20);
        while(t[i]-t[p1]>=90)p1++;
        dp[i]=min(dp[i],q1.query(p1-1)+50);
        while(t[i]-t[p2]>=1440)p2++;
        dp[i]=min(dp[i],q2.query(p2-1)+120);
        q1.add(dp[i],i),q2.add(dp[i],i);
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",dp[i]-dp[i-1]);
    return 0;
}