#include <bits/stdc++.h>

using namespace std;


set<int> S;

int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            S.insert(i);
            S.insert(n / i);
        }
    }

    for (auto it = S.rbegin(); it != S.rend(); ++it) {
        const long long val = *it;
        const long long skip = n / val;

        long long total = skip * (skip-1) / 2 * val + skip;
        cout << total << " ";
    }
    cout << endl;

    return 0;
}