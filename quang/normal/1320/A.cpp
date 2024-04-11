#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];
int b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long res = 0;
    cin >> n;
    map<int, long long> m;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        a[i] = b[i] - i;
        m[a[i]] += b[i];
    }
    for (auto u : m) {
        res = max(res, u.second);
    }
    cout << res << endl;
    return 0;
}