#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll l,r,x,y,k;
    scanf("%lld%lld%lld%lld%lld",&l,&r,&x,&y,&k);
    for(ll i=x;i<=y;i++)
        if(i*k>=l && i*k<=r)
            return 0*printf("YES\n");
    return 0*printf("NO\n");
}