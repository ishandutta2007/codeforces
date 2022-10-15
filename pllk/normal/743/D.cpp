#include <iostream>
#include <vector>

#define A 999999999999999

using namespace std;

typedef long long ll;

int n;
ll a[202020];
vector<int> v[202020];
ll d1[202020];
ll d2[202020];
ll uu = -A;

void haku(int s, int e) {
    ll z = a[s];
    d2[s] = -A;
    ll u1 = -A, u2 = -A;
    for (auto u : v[s]) {
        if (u == e) continue;
        haku(u, s);
        z += d1[u];
        d2[s] = max(d2[s],d2[u]);
        if (d2[u] > u1) {
            u2 = u1;
            u1 = d2[u];
        } else if (d2[u] > u2) {
            u2 = d2[u];
        }
    }
    d1[s] = z;
    d2[s] = max(d2[s],d1[s]);
    if (u2 > -A) uu = max(uu,u1+u2);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    haku(1,0);
    if (uu == -A) cout << "Impossible\n";
    else cout << uu << "\n";
}