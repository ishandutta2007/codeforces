#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    scanf("%lld",&n);
    printf("%lld\n",n==0 ? 0 : (n&1 ? (n+1)/2 : n+1));
    return 0;
}