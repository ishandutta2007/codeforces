#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    ll ans=1;
    for (int i=1;i<=(n/2);i++) ans= ans*(n-i+1)/i;
    ans /= 2;
    ll fact=1;
    for (int i=1;i<(n/2);i++) fact *= i;
    ans *= (fact*fact);
    printf("%lld", ans);
    return 0;
}