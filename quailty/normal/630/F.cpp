#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll C(ll n,ll k)
{
    if(k>n)return 0;
    ll res=1;
    for(int i=1;i<=k;i++)
    {
        res*=n+1-i;
        res/=i;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%I64d\n",C(n,5)+C(n,6)+C(n,7));
    return 0;
}