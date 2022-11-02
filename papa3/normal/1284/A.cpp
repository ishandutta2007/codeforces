#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

const int INF = 1000000000000000000LL;
const int mod = 1000000007;

string s[1000], t[1000];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
         cin >> s[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> t[i];
    }
    
    int q;
    cin >> q;
    int x;
    int nww = n * m / __gcd(n, m);
    while (q--) {
        cin >> x;
        x %= nww;
        int nn = n, mm = m;
        while (x--) {
            nn = nn % n + 1;
            mm = mm % m + 1;
        }
        cout << s[nn] << t[mm] << "\n";
    }
    return 0;
}