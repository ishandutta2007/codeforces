#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i, n, x;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        cin >> n >> x;

        vector <int> a(n);
        bool ok = 0;
        for(i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == x) {
                ok = 1;
            }
        }
        sort(a.begin(), a.end());

        int ans = x / a[n - 1];
        if(x % a[n - 1]) {
            ans++;
        }
        ans = max(ans, 2);
        if(ok) {
            ans = 1;
        }
        cout << ans << "\n";
    }

    return 0;
}