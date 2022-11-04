#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m,k,res=0;
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    k++;
    for(ll t,_=0;_<2;_++)
    {
        for(t=1;t*t<=n && t<=k;t++)
            res=max(res,(n/t)*(m/(k+1-t)));
        for(t=n/t;t>=1 && n/t<=k;t--)
            res=max(res,t*(m/(k+1-n/t)));
        swap(n,m);
    }
    return 0*printf("%I64d",res-(res==0));
}