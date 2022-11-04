#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1000005;
int p[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    ll now=0,big=0;
    priority_queue<pair<int,int> > pq;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        now+=abs(p[i]-i);
        if(p[i]>i)pq.push(make_pair(i-p[i],i)),big++;
    }
    ll res=now,loc=0;
    for(int i=1;i<n;i++)
    {
        now+=n-2*big;
        now-=abs(p[n-i+1]-(n+1));
        now+=abs(p[n-i+1]-1);
        pq.push(make_pair(1-p[n-i+1]-i,n-i+1)),big++;
        while(!pq.empty() && pq.top().first==-i)pq.pop(),big--;
        if(res>now)res=now,loc=i;
    }
    printf("%lld %lld\n",res,loc);
    return 0;
}