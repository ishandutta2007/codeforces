#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;

    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = 0, best = 0, cur = 0, ind = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        cur += 1;
        if (sum > t) {
            sum -= a[ind];
            cur -= 1;
            ind += 1;
        }
        best = max(best, cur);
    }

    cout << best;
    return 0;
}