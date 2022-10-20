#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int a[N], b[N];
int posA[N], posB[N];

void swapPair(int *a, int *posA, int u, int v) {
    swap(a[u], a[v]);
    posA[a[u]] = u;
    posA[a[v]] = v;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        posA[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        posB[b[i]] = i;
    }
    vector<tuple<int, int, int, int>> res;
    for (int i = 1; i <= n; i++) {
        if (a[i] == i && b[i] == i) continue;
        res.push_back({i, posB[i], posA[i], i});
        swapPair(a, posA, i, posA[i]);
        swapPair(b, posB, i, posB[i]);
    }
    cout << res.size() << '\n';
    for (auto u : res) {
        int x, y, xx, yy;
        tie(x, y, xx, yy) = u;
        cout << x << ' ' << y << ' ' << xx << ' ' << yy << '\n';
    }
    return 0;
}