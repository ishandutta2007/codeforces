#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int tot = a[1];
    vector<int> res = {1};
    for (int i = 2; i <= n; i++) {
        if (a[i] * 2 <= a[1]) {
            res.push_back(i);
            tot += a[i];
        }
    }
    if (tot * 2 <= sum) {
        cout << 0 << endl;
    } else {
        cout << res.size() << endl;
        for (int u : res) cout << u << ' ';
            cout << endl;
    }
    return 0;
}