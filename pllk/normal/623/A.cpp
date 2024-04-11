#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int n, m;
int d[555][555];

vector<int> v[555];

int c[555];

void haku(int s, int x) {
    if (c[s] == x) return;
    if (c[s] && c[s] != x) {
        cout << "No\n";
        exit(0);
    }
    c[s] = x;
    for (int i = 0; i < v[s].size(); i++) {
        int u;
        if (x == 1) u = 3;
        else u = 1;
        haku(v[s][i], u);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (a == b) continue;
            if (!d[a][b]) v[a].push_back(b);
        }
    }
    bool lol = false;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() == 0) {
            c[i] = 2;
            continue;
        }
        if (c[i]) continue;
        if (lol) {
            cout << "No\n";
            exit(0);
        }
        haku(i,1);
        lol = true;
    }
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (a == b) continue;
            if (!d[a][b]) continue;
            bool ok = true;
            if (c[a] == 1 && c[b] == 3) ok = false;
            if (c[a] == 3 && c[b] == 1) ok = false;
            if (!ok) {
                cout << "No\n";
                exit(0);
            }
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << (char)('a'+(c[i]-1));
    }
    cout << "\n";
}