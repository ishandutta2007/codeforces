#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll x[1000005],y[1000005];
priority_queue<ll>q;
int main()
{
    int n,m,k,p;
    scanf("%d%d%d%d",&n,&m,&k,&p);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int a;
            scanf("%d",&a);
            x[i]+=a;
            y[j]+=a;
        }
    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++)
        q.push(x[i]);
    for(int i=1;i<=k;i++)
    {
        ll t=q.top();
        q.pop();
        x[i]=x[i-1]+t;
        q.push(t-m*p);
    }
    while(!q.empty())q.pop();
    for(int i=1;i<=m;i++)
        q.push(y[i]);
    for(int i=1;i<=k;i++)
    {
        ll t=q.top();
        q.pop();
        y[i]=y[i-1]+t;
        q.push(t-n*p);
    }
    ll res=-(1LL<<60);
    for(int i=0;i<=k;i++)
        res=max(res,x[i]+y[k-i]-1LL*i*(k-i)*p);
    printf("%I64d",res);
    return 0;
}