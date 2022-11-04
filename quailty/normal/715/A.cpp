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
    ll n;
    scanf("%I64d",&n);
    for(ll i=1;i<=n;i++)
        printf("%I64d\n",i*(i+1)*(i+1)-(i-1)-(i==1)*2);
    return 0;
}