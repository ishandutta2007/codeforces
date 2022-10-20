#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<ll, int> a[100100];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", &a[i].second);
    for (int i=1;i<=n;i++) scanf("%lld", &a[i].first);

    vector<ll> V[2];
    for (int i=1;i<=n;i++) V[a[i].second].push_back(a[i].first);

    sort(V[0].begin(), V[0].end(), greater<int>());
    sort(V[1].begin(), V[1].end(), greater<int>());

    int cnt = min(V[0].size(), V[1].size());
    ll ans = 0;

    for (int i=0;i<cnt;i++) ans += V[0][i] + V[1][i];
    if (V[0].size()==V[1].size()) ans -= min(V[0][cnt-1], V[1][cnt-1]);

    for (auto &x:V[0]) ans += x;
    for (auto &x:V[1]) ans += x;
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