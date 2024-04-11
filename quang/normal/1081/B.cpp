#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int res[N];
vector<int> a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        a[n - u].push_back(i);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].size() % i != 0) {
            cout << "Impossible" << endl;
            return 0;
        }
        for (int j = 0; j < a[i].size(); j += i) {
            cnt++;
            for (int k = 0; k < i; k++) {
                res[a[i][j + k]] = cnt;
            }
        }
    }
    if (cnt > n) {
        cout << "Impossible" << endl;
            return 0;
    }
    cout << "Possible" << endl;
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
        cout << endl;
    return 0;
}