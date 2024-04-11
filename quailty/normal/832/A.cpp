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
    ll n,k;
    scanf("%lld%lld",&n,&k);
    printf("%s\n",((n/k)%2 ? "YES" : "NO"));
    return 0;
}