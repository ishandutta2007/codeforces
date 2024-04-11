#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int n, m;
int a[N];
int to[N];
bool used[N];

int findTo() {
    int id = -1;
    for (int i = 1; i <= n * 2; i++) {
        if (!to[i] || used[i]) continue;
        if (id == -1 || a[id] < a[i]) {
            id = i;
        }
    }
    return id;
}

int find() {
    int id = -1;
    for (int i = 1; i <= n * 2; i++) {
        if (!used[i]) {
            if (id == -1 || a[id] < a[i]) {
                id = i;
            }
        }
    }
    return id;
}

void output(int u) {
    used[u] = 1;
    cout << u << endl;
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n * 2; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        to[u] = v;
        to[v] = u;
    }
    int t;
    cin >> t;
    t--;
    int last = -1;
    for (int i = 1; i <= n * 2; i++, t ^= 1) {
        if (t) {
            int id;
            cin >> id;
            used[id] = 1;
            if (to[id]) {
                last = id;
            }
        } else {
            if (last != -1) {
                if (!used[to[last]]) {
                    output(to[last]);
                    continue;
                }
                last = -1;
            }
            int id = findTo();
            if (id != -1) {
                output(id);
            } else {
                id = find();
                output(id);
            }
        }
    }
    return 0;
}