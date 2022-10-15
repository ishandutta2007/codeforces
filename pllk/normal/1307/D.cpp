#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int a[202020];
vector<int> v[202020];
int e[202020];
int f[202020];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    e[1] = 0;
    for (int i = 2; i <= n; i++) e[i] = 1e9;
    vector<int> q;
    q.push_back(1);
    for (int i = 0; i < q.size(); i++) {
        int s = q[i];
        for (auto u : v[s]) {
            if (e[u] == 1e9) {
                e[u] = e[s]+1;
                q.push_back(u);
            }
        }
    }
    
    
    f[n] = 0;
    for (int i = 1; i <= n-1; i++) f[i] = 1e9;
    q.clear();
    q.push_back(n);
    for (int i = 0; i < q.size(); i++) {
        int s = q[i];
        for (auto u : v[s]) {
            if (f[u] == 1e9) {
                f[u] = f[s]+1;
                q.push_back(u);
            }
        }
    }
    
    vector<pair<int,int>> w;
    for (int i = 1; i <= n; i++) {
        if (a[i]) w.push_back({f[i],i});
    }
    sort(w.rbegin(),w.rend());
    int g = 0;
    int h = 0;
    for (int i = 0; i < k; i++) {
        if (i != 0) {
            h = max(h,g+w[i].first+1);
        }
        g = max(g,e[w[i].second]);
    }
    h = min(h,e[n]);
    cout << h << "\n";
}