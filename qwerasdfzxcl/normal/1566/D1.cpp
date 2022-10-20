#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<int, int> a[100100];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<m;i++){
        scanf("%d", &a[i].first);
        a[i].second = -i;
    }
    sort(a, a+m);
    ll ans = 0;
    for (int i=0;i<m;i++){
        for (int j=0;j<i;j++) if (-a[i].second>-a[j].second) ans++;
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