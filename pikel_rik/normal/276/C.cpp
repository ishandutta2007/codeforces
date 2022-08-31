#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vi prefix(n + 1);
    while (q--) {
        int l, r;
        cin >> l >> r;

        prefix[l-1] += 1;
        prefix[r] -= 1;
    }

    for (int i = 1; i <= n; i++) {
        prefix[i] += prefix[i-1];
    }
    sort(prefix.begin(), prefix.end());
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += prefix[i] * (ll)a[i-1];
    }

    cout << sum;
    return 0;
}