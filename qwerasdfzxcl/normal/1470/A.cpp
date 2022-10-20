#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[300300], b[300300];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    for (int i=0;i<m;i++) scanf("%d", b+i);
    sort(a, a+n, greater<int>());
    int cur=0;
    ll ans=0;
    for (int i=0;i<n;i++){
        if (cur>a[i]-1){
            ans += b[a[i]-1];
            continue;
        }
        ans += b[cur];
        cur++;
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