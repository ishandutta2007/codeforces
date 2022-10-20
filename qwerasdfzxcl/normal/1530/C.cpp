#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], b[100100];
ll S[100100], T[100100];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    for (int i=0;i<n;i++) scanf("%d", b+i);
    sort(a, a+n);
    sort(b, b+n);
    for (int i=1;i<=n;i++) S[i] = S[i-1] + a[i-1];
    for (int i=1;i<=n;i++) T[i] = T[i-1] + b[i-1];
    int l = 0, r = n*8, ans = 1e9;
    while(l<r){
        int m = (l+r)>>1;
        ll tmp = 0;
        if ((m+n)/4>=n) tmp = (ll)(m+n-(m+n)/4)*100;
        else tmp = (ll)m*100+S[n] - S[(m+n)/4];

        ll tmp2 = T[n];
        if ((m+n)/4>m) tmp2 = T[n] - T[(m+n)/4-m];
        if (tmp>=tmp2) r = m, ans = m;
        else l = m+1;
    }
    assert(ans!=1e9);
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}