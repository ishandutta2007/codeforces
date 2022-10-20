#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[500500];
ll S[100100];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    sort(a, a+n);
    S[n-1] = 0;
    for (int i=n-2;i>=0;i--) S[i] = S[i+1] + a[n-1] - a[i];
    ll ans = 0;
    for (int i=2;i<n;i++){
        ans -= (S[0]-S[i-1]) - ((ll)(a[n-1]-a[i])*(i-1));

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