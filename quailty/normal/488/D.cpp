#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
int a[MAXN],t[MAXN],dp[MAXN];
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
}mx,mi;
int main()
{
    int n,s,l;
    scanf("%d%d%d",&n,&s,&l);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    mx.init();
    mi.init();
    for(int i=n,j=n;i>=1;i--)
    {
        while(j>0 && -mx.query(-i)-mi.query(-i)<=s)
        {
            mx.add(-a[j],-j);
            mi.add(a[j],-j);
            j--;
        }
        t[i]=j+(-mx.query(-i)-mi.query(-i)>s);
    }
    memset(dp,INF,sizeof(dp));
    dp[0]=0;
    mi.init();
    for(int i=1,j=0;i<=n;i++)
    {
        while(j<=i-l)
        {
            mi.add(dp[j],j);
            j++;
        }
        dp[i]=mi.query(t[i])+1;
    }
    return 0*printf("%d",(dp[n]<INF ? dp[n] : -1));
}