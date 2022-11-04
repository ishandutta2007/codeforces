#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll c[MAXN],t[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    ll sum=0,res=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&c[i]);
        sum+=c[i];
    }
    for(int i=1;i<=k;i++)
    {
        int id;
        scanf("%d",&id);
        t[id]=1;
    }
    for(int i=1;i<=n;i++)
        if(t[i])res+=(sum-c[i])*c[i];
    for(int i=1;i<=n;i++)
        res-=(min(t[i]+t[i%n+1],1LL)-1)*c[i]*c[i%n+1];
    ll sum1=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        if(!t[i])continue;
        sum1+=c[i];
        sum2+=c[i]*c[i];
    }
    res-=(sum1*sum1-sum2)/2;
    return 0*printf("%I64d",res);
}