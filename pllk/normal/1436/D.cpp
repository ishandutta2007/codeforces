#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
ll x;
ll a[202020];
vector<int> p[202020];
bool f;

ll dfs(int s) {
    if (p[s].size() == 0) {
        if (a[s] > x) f = true;
        return x-a[s];
    }
    ll w = 0;
    for (auto u : p[s]) {
        w += dfs(u);
        if (w > 1e16) w = 1e16;
        if (f) return 0;
    }
    w -= a[s];
    if (w < 0) f = true;
    return w;
}

bool check(ll b) {
    x = b;
    f = false;
    dfs(1);
    return !f;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        p[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll k = -1;
    int c = 0;
    for (ll b = 1LL<<48; b >= 1; b /= 2) {
        if (!check(k+b)) k += b;
        c++;
    }
    cout << k+1 << "\n";
}