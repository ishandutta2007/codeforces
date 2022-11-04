#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll p[100005];
int main()
{
    ll s,f,t;
    scanf("%lld%lld%lld",&s,&f,&t);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&p[i]);
    ll now=s,res=(1LL<<60)-1,loc=-1;
    for(int i=1;i<=n && p[i]<=f-t+1;i++)
    {
        if(p[i]!=p[i-1])
        {
            ll tmp=max(0LL,now-p[i]+1);
            if(res>tmp)res=tmp,loc=p[i]-1;
        }
        now=max(now,p[i])+t;
    }
    if(now<=f-t)res=0,loc=f-t;
    return 0*printf("%lld",loc);
}