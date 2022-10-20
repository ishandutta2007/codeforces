#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO\n";
        return 0;
    }
    vector<int> res(n + n + 1);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            res[i] = ++cur;
            res[i + n] = ++cur;
        } else {
            res[i + n] = ++cur;
            res[i] = ++cur;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n * 2; i++) cout <<res[i] << ' ';
        cout << endl;
    return 0;
}