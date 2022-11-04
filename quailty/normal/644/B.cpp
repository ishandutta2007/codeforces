#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll t[MAXN],d[MAXN],res[MAXN];
queue<pair<ll,int> >q;
int main()
{
    int n,b,r=0;
    scanf("%d%d",&n,&b);
    for(int i=1;i<=n;i++)
        scanf("%I64d%I64d",&t[i],&d[i]);
    ll now=0;
    while(1)
    {
        while(!q.empty())
        {
            if(r<=n && t[r]<now)break;
            now=res[q.front().second]=now+q.front().first;
            q.pop();
        }
        while(r<=n && t[r]<now)
        {
            if((int)q.size()<b)q.push(make_pair(d[r],r));
            else res[r]=-1;
            r++;
        }
        if(q.empty() && r<=n && t[r]>=now)
        {
            now=res[r]=t[r]+d[r];
            r++;
        }
        if(r>n && q.empty())break;
    }
    for(int i=1;i<=n;i++)
        printf("%I64d ",res[i]);
    return 0;
}