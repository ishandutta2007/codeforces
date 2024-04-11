#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
int cnt[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++) {
            int u;
            cin >> u;
            cnt[u]++;
        }
    }
    for (int i = 1; i <= 100; i++) {
        if (cnt[i] == n) {
            cout << i << ' ';
        }
    }
    cout << endl;
    return  0;
}