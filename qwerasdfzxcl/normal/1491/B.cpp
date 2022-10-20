#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];

void solve(){
    int n;
    ll u, v;
    scanf("%d %lld %lld", &n, &u, &v);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    bool test=1;
    ll ans=0;
    for (int i=0;i<n-1;i++){
        if (abs(a[i]-a[i+1])>=2) test=0;
    }
    if (test){
        sort(a, a+n);
        if (a[0]==a[n-1]) ans=min(v*2, v+u);
        else ans=min(v, u);
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