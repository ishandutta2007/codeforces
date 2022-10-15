#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int d[101010];
int a[101010];
int c;
int h[101010];
int z[101010];
int e[101010];

bool ok(int k) {
    c++;
    vector<int> v;
    for (int i = k; i >= 1; i--) {
        if (d[i] == 0) continue;
        if (h[d[i]] != c) {
            h[d[i]] = c;
            z[i] = c;
            e[d[i]] = 0;
            v.push_back(d[i]);
        }
    }
    if (v.size() != m) return false;
    reverse(v.begin(),v.end());
    int j = 0;
    for (int i = 1; i <= k; i++) {
        if (z[i] == c) {
            if (e[d[i]] != a[d[i]]) return false;
        } else if (j < v.size()) {
            e[v[j]]++;
            if (e[v[j]] == a[v[j]]) j++;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= m; i++) cin >> a[i];
    int u = 0;
    for (int b = n; b >= 1; b /= 2) {
        while (u+b <= n && !ok(u+b)) u += b;
    }
    if (u == n) cout << "-1\n";
    else cout << u+1 << "\n";
}