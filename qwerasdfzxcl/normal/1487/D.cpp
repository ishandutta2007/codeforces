#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    ll n;
    scanf("%lld", &n);
    ll cnt=1;
    for (;cnt<=1000000;cnt++) if (cnt*cnt>2*n-1) break;
    cnt--;
    cnt=(cnt+1)/2-1;
    printf("%lld\n", cnt);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}