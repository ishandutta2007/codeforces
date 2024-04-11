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
    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        sort(a.begin() + 1, a.end(), greater<ll>());
        sort(b.begin() + 1, b.end(), greater<ll>());

        for (int i = 1; i <= n; i++) {
            a[i] += a[i - 1];
            b[i] += b[i - 1];
        }

        int N = n;
        while (true) {
            int sz = N - N / 4;
            int cnt = min(N - n, sz);

            if (t == 2 && N == 7) {
                cerr << sz << " " << a[sz - cnt] + 100 * cnt << "\n";
            }

            if (a[sz - cnt] + 100 * cnt >= b[min(sz, n)]) {
                break;
            }
            N++;
        }

        cout << N - n << "\n";
    }

    return 0;
}