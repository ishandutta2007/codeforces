#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9;
const ll mod = 998244353;

void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;

    int res = inf;
    int st_sum = 0;
    for (int st = 0; st < n; ++st) {
        st_sum += a[st];
        int mx = st+1;

        int sum = 0;
        for (int l = st+1, r = st+1; r < n; ++r) {
            sum += a[r];
            if (sum > st_sum) {
                mx = inf;
            }
            if (sum == st_sum) {
                chmax(mx, r - l + 1);
                l = r+1;
                sum = 0;
            } else if (r == n-1) {
                mx = inf;
            }
        }
        chmin(res, mx);
    }
    cout << res << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}