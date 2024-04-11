#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];

int myabs(int x){
    if (x<0) return -x;
    return x;
}

void solve(){
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        a[i] = a[i]&1;
        if (a[i]) cnt++;
    }
    if (myabs(cnt - (n-cnt))>=2) {printf("-1\n"); return;}
    ll rans = 1e18;
    if (cnt==n/2){
        int cur = 0;
        ll ans = 0;
        for (int i=0;i<n;i++) if (a[i]){
            ans += myabs(cur*2+1 - i);
            cur++;
        }
        rans = min(rans, ans);
    }
    if ((n-cnt)==n/2){
        int cur = 0;
        ll ans = 0;
        for (int i=0;i<n;i++) if (a[i]){
            ans += myabs(cur*2 - i);
            cur++;
        }
        rans = min(rans, ans);
    }
    printf("%lld\n", rans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}