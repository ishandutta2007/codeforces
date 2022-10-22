#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll a[200002], b[200002];

ll gcd(ll x, ll y){
    if(x == 0) return y;
    if(y == 0) return x;
    if(x > y) swap(x, y);
    if(y % x == 0) return x;
    return gcd(x, y%x);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%lld", &a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%lld", &b[i]);
    }

    ll gcda = 0;
    for(int i=1;i<n;i++){
        ll temp;
        temp = gcd(gcda, abs(a[i] - a[i-1]));
        gcda = temp;
    }

    for(int i=0;i<m;i++){
        ll ans;
        ans = gcd(a[0] + b[i], gcda);
        printf("%lld ", ans);
    }
}