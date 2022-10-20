#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200], b[200200];
ll d[200200], ans[200200];

void solve(){
    int n;
    ll c;
    scanf("%d %lld", &n, &c);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    for (int j=0;j<n-1;j++) scanf("%d", b+j);
    d[0]=0;
    ll cur = 0;
    if (c>cur) ans[0] = (c-cur-1)/a[0] + d[0] +1;
    ll rans=ans[0];
    for (int i=1;i<n;i++){
        d[i] = d[i-1]+1;
        if (b[i-1]-cur>0){
            d[i] += (b[i-1]-cur-1)/a[i-1]+1;
            cur += (ll)a[i-1]*((b[i-1]-cur-1)/a[i-1]+1);
        }
        cur -= b[i-1];
        ans[i] = d[i];
        if (c>cur) ans[i] += (c-cur-1)/a[i] + 1;
        rans = min(rans, ans[i]);
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