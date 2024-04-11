#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 998244353ll
#define INF 1000000000000000000ll

#define MAX_N 1000010

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int pocz = 0, kon = s.size() - 2;

    string res = "";

    while (kon + 1 >= pocz) {
        if (pocz + 1 >= kon) {
            cout << res;
            cout << s[pocz];
            reverse(res.begin(), res.end());
            cout << res;
            return 0;
        }

        bool czy = false;
        for (int i = pocz; i < pocz + 2 && !czy; i++) {
            for (int j = kon; j < kon + 2 && !czy; j++) {
                if (s[i] == s[j]) {
                    res.push_back(s[i]);
                    czy = true;
                }
            }
        }

        pocz += 2;
        kon -= 2;
    }

    cout << res;
    reverse(res.begin(), res.end());
    cout << res;

    return 0;
}
/*

*/