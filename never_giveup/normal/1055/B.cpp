#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

void setmax(int &x, int y){
    x = max(x, y);
}

const int maxn = 1e5 + 100, inf = 1e9 + 100;

int p[maxn];

int get(int x){
    return x == p[x] ? x : p[x] = get(p[x]);
}

bool uni(int x, int y){
    x = get(x);
    y = get(y);
    if (x == y)
    return 0;
    p[x] = y;
    return 1;
}

int n, m;

ll l;

ll a[maxn];

int go(int x){
    if (x >= 0 && x < n - 1 && a[x] > l && a[x + 1] > l)
        return uni(x, x + 1);
    return 0;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++)
        p[i] = i;
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], ans += (a[i] > l);
    for (int i = 0; i < n - 1; i++)
        ans -= go(i);
    for (int i = 0; i < m; i++){
        int t;
        cin >> t;
        if (t == 0){
            cout << ans << '\n';
        } else {
            int id;
            ll w;
            cin >> id >> w;
            id--;
            if (a[id] <= l && a[id] + w > l)
                ans++;
            a[id] += w;
            ans -= go(id - 1) + go(id);
        }
    }
}