#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";


using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }

        auto check = [&](int num) {
            int pos = 0;
            for (int i = 0; i < n; i++) {
                if (b[i] >= pos && a[i] >= num - pos - 1) {
                    pos++;
                    if (pos == num) {
                        return true;
                    }
                }
            }
            return false;
        };

        int res = 0;
        for (int step = 1 << 20; step; step >>= 1) {
            if (check(res + step)) {
                res += step;
            }
        }

        cout << res << "\n";
    }
    

   
    return 0;
}