#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)(a.size())
#define all(_v) _v.begin(), _v.end()
typedef long double ld;

const int inf = 1e15;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a = 0, b = 0, c = 0;
        for(int i = 2;i * i <= n;i++) {
            if (n % i == 0) {
                n /= i;

                if (a == 0) a = i;
                else if (b == 0) {
                    b = i;
                    break;
                }
            }
        }

        if (n == 1 || b == 0 || n == b) cout << "NO" << endl;
        else {
            cout << "YES" << endl << a << " " << b << " " << n << endl;
        }
    }
}