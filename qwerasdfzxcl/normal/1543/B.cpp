#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[200200];

void solve(){
    int n;
    scanf("%d", &n);
    ll s = 0;
    for (int i=0;i<n;i++){
        scanf("%lld", a+i);
        s += a[i];
    }
    s %= n;
    printf("%lld\n", s*(n-s));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}