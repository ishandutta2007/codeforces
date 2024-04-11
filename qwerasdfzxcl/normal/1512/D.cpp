#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll b[200200];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n+2;i++) scanf("%lld", b+i);
    sort(b, b+n+2);
    ll s=0;
    for (int i=0;i<n+1;i++) s += b[i];
    int idx=-1;
    for (int i=0;i<n+1;i++) if (s-b[i]==b[n+1]){
        idx=i; break;
    }
    if (idx!=-1){
        for (int i=0;i<n+1;i++) if (i!=idx) printf("%lld ", b[i]);
        printf("\n"); return;
    }
    s -= b[n];
    if (s == b[n]){
        for (int i=0;i<n;i++) printf("%lld\n", b[i]);
        printf("\n"); return;
    }
    printf("-1\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}