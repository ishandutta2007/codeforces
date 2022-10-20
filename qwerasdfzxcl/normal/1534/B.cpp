#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[400400];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    if (n==1){
        printf("%d\n", a[0]); return;
    }
    ll ans = a[0]+a[n-1];
    for (int i=1;i<n;i++) ans += abs(a[i]-a[i-1]);
    for (int i=0;i<n;i++){
        int tmp1 = -1, tmp2 = -1;
        if (i) tmp1 = a[i-1];
        if (i<n-1) tmp2 = a[i+1];
        if (tmp1<a[i] && tmp2<a[i]) ans -= a[i]-max(tmp1, tmp2);
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}