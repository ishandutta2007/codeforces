#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<int, int> a[200200], b[200200];
int cnt[200200], ans[200200];

bool cmp(pair<int, int> x, pair<int, int> y){
    if (x.second==y.second) return x.first < y.first;
    return x.second < y.second;
}

void solve(){
    int n;
    scanf("%d", &n);
    fill(cnt+1, cnt+n+1, 0);
    fill(cnt+1, cnt+n+1, -1);
    map<pair<int, int>, int> mp;
    for (int i=1;i<=n;i++){
        scanf("%d", &a[i].first);
        a[i].second = ++cnt[a[i].first];

        b[i] = a[i];
        mp[a[i]] = i;
    }

    sort(b+1, b+n+1, cmp);
    for (int i=1;i<=n;i++){
        ans[mp[b[i%n+1]]] = b[i].first;
    }
    for (int i=1;i<=n;i++) printf("%d ", ans[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}