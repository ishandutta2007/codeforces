#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> D[200200];
vector<ll> b[200200];
multiset<ll> pq[200200];
ll a[200200];
int prime[200200];

void solve(){
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i=1;i<=n;i++) scanf("%lld", a+i);

    ll mx = 0;
    for (auto &d:D[n]){
        b[d].reserve(d);
        for (int i=1;i<=d;i++){
            b[d].push_back(0);
            for (int j=i;j<=n;j+=d){
                b[d].back() += a[j] * d;
            }

            pq[d].emplace(b[d].back());
        }
        mx = max(mx, *pq[d].rbegin());
    }
    printf("%lld\n", mx);

    while(q--){
        int x, y;
        scanf("%d %d", &x, &y);
        ll delta = y - a[x];

        for (auto &d:D[n]){
            int idx = (x-1) % d;
            pq[d].erase(pq[d].find(b[d][idx]));
            b[d][idx] += delta * d;
            pq[d].emplace(b[d][idx]);
        }
        a[x] = y;

        mx = 0;
        for (auto &d:D[n]){
            mx = max(mx, *pq[d].rbegin());
        }
        printf("%lld\n", mx);
    }

    for (auto &d:D[n]){
        b[d].clear();
        pq[d].clear();
    }
}

int main(){
    fill(prime+2, prime+200000+1, 1);
    for (int i=2;i<=200000;i++){
        if (!prime[i]) continue;
        for (int j=i;j<=200000;j+=i){
            prime[j] = 0;
            D[j].push_back(j/i);
        }
    }

    for (int i=2;i<=200000;i++) {
        sort(D[i].begin(), D[i].end());
    }

    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}