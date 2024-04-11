#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int a[N];

bool check(int u) {
    for (int i = u + 1; i <= n; i++) {
        if (a[i] != a[i - u]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i; i--) {
        a[i] -= a[i - 1];
    }
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (check(i)) {
            res.push_back(i);
        }
    }
    cout << (int)res.size() << '\n';
    for (int u : res) {
        cout << u << ' ';
    }
    cout << '\n';
    return 0;
}