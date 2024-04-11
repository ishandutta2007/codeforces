#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    ll ans = 0;
    for (int i=0;i<n;i++){
        int tmp;
        scanf("%d", &tmp);
        ans += tmp;
    }
    if (ans>=n) printf("%lld\n", ans-n);
    else printf("1\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}