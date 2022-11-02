#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

#define MAX_N 1000010

char lit[1000];

struct algo {
    int n;

    string a, b;

    algo() {
        cin >> n;

        cin >> a >> b;
        for (char c = 'a'; c <= 'z'; c++) {
            lit[c] = 0;
        }

        for (char c : a) lit[c]++;
        for (char c : b) lit[c]--;

        for (char c = 'a'; c <= 'z'; c++) {
            if (lit[c]) {
                cout << "-1\n";
                return;
            }
        }

        int res = 0;
        for (int pocz = 0; pocz < b.size(); pocz++) {
            int gdzie = 0;
            for (int i = pocz; i < b.size(); i++) {
                while (gdzie < n && a[gdzie] != b[i]) gdzie++;
                if (gdzie == n) {
                    break;
                } else {
                    res = max(res, i - pocz + 1);
                    gdzie++;
                }
            }
        }

        cout << n - res << "\n";
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        algo p;
    }

    return 0;
}
/*

*/