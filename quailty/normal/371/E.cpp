#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=300005;
ll x[MAXN],y[MAXN];
int p[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&x[i]);
    for(int i=1;i<=n;i++)p[i]=i;
    sort(p+1,p+n+1,[](int a,int b){return x[a]<x[b];});
    sort(x+1,x+n+1);
    for(int i=1;i<=n;i++)
        y[i]=y[i-1]+x[i];
    int k,loc=1;
    scanf("%d",&k);
    ll res=0,now=0;
    for(int i=k+1;i<=n;i++)
    {
        now-=(y[i-1]-y[i-k])-(k-1)*x[i-k];
        now+=(k-1)*x[i]-(y[i-1]-y[i-k]);
        if(res>now)res=now,loc=i-k+1;
    }
    for(int i=loc,j=1;j<=k;i++,j++)
        printf("%d ",p[i]);
    return 0;
}