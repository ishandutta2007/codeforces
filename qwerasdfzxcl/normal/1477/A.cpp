#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[200200];

void solve(){
    int n;
    ll k;
    scanf("%d %lld", &n, &k);
    for (int i=0;i<n;i++) scanf("%lld", a+i);
    sort(a, a+n);
    ll val = abs(a[1]-a[0]);
    for (int i=1;i<n-1;i++) val = __gcd(val, abs(a[i+1]-a[i]));
    ll tmp1 = k%val, tmp2=abs(a[0])%val;
    if (k<0 && tmp1) tmp1 = val-(-k)%val;
    if (a[0]<0 && tmp2) tmp2=val-tmp2;
    //printf("%lld %lld %lld\n", val, tmp1, tmp2);
    bool ans=(tmp1==tmp2);
    if (ans) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}