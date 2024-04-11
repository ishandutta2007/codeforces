#include <iostream>
#include <vector>

using namespace std;

#define ll long long

vector<int> v[101010];
int n, m;

int k[101010];
bool b = true;

int kc[3];

void haku(int s, int u) {
    if (k[s] != 0 && k[s] != u) {
        b = false;
        return;
    }
    if (k[s] == u) return;
    kc[u]++;
    k[s] = u;
    for (int i = 0; i < v[s].size(); i++) {
        haku(v[s][i], 3-u);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if (m == 0) {
        cout << 3 << " " << (ll)n*(n-1)*(n-2)/6 << "\n";
        return 0;
    }
    ll kz = 0;
    for (int i = 1; i <= n; i++) {
        if (k[i]) continue;
        kc[1] = 0;
        kc[2] = 0;
        haku(i,1);
        kz += (ll)kc[1]*(kc[1]-1)/2;
        kz += (ll)kc[2]*(kc[2]-1)/2;
    }
    if (!b) {
        cout << 0 << " " << 1 << "\n";
        return 0;
    }
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() >= 2) ok = true;
    }
    if (ok) {
        cout << 1 << " " << kz << "\n";
    } else {
        ll c = 0;
        for (int i = 1; i <= n; i++) {
            if (v[i].size() == 1) c += n-2;
        }
        cout << 2 << " " << c/2 << "\n";
    }
}