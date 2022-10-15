#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int,int>> v[303030];
int z[303030];

void lol() {
    cin >> n >> m;
    for (int i = 1; i <= 3*n; i++) v[i].clear();
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    for (int i = 1; i <= 3*n; i++) z[i] = 0;
    vector<int> e;
    for (int i = 1; i <= 3*n; i++) {
        if (z[i]) continue;
        for (auto u : v[i]) {
            if (z[u.first]) continue;
            z[i] = z[u.first] = 1;
            e.push_back(u.second);
            break;
        }
    }
    if (e.size() >= n) {
        cout << "Matching\n";
        for (int i = 0; i < n; i++) cout << e[i] << " ";
        cout << "\n";
    } else {
        cout << "IndSet\n";
        int c = 0;
        for (int i = 1; i <= 3*n; i++) {
            if (z[i]) continue;
            cout << i << " ";
            c++;
            if (c == n) break;
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) lol();
}