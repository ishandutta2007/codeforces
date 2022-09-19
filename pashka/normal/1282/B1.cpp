#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    long s1 = 0;
    /// x x . . . x . . . x . .
    int res = 0;
    for (int i = 0; i < k; i++) {
        if (s1 > p) {
            break;
        }
        int j = i + k - 1;
        int x = i;
        long s = s1;
//        cerr << i << " " << s1 << " ";
        while (j < n && s + a[j] <= p) {
            s += a[j];
            x += k;
            j += k;
//            cerr << j << " ";
        }
//        cerr << "\n";
        res = max(res, x);
        s1 += a[i];
    }
    cout << res << "\n";
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