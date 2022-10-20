#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[200200], b[200200];

ll gcd(ll x, ll y){
    if (y==0) return x;
    if (x==0) return y;
    if (x<y) swap(x, y);
    return gcd(x%y, y);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++) scanf("%lld", a+i);
    for (int i=0;i<m;i++) scanf("%lld", b+i);
    sort(a, a+n);
    ll tgcd;
    if (n>1) tgcd=a[1]-a[0];
    else tgcd=0;
    for (int i=2;i<n;i++){
        tgcd=gcd(tgcd, a[i]-a[0]);
    }
    for (int i=0;i<m;i++) printf("%lld ", gcd(tgcd, a[0]+b[i]));
    return 0;
}