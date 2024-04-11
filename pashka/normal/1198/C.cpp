#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

void solve_test() {
    int n, m;
    cin >> n >> m;
    vector<bool> used(3 * n);
    vector<int> res;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (!used[u]&& !used[v]) {
            res.push_back(i + 1);
            used[u] = used[v] = true;
        }
    }
    if (res.size() >= n) {
        cout << "Matching\n";
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "IndSet\n";
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (used[j]) j++;
            cout << j + 1 << " ";
            used[j] = true;
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}