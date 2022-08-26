#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int get_xor(int a, int b) {
    cout << "XOR " << a + 1 << " " << b + 1 << endl;
    int x;
    cin >> x;
    return x;
}

int get_and(int a, int b) {
    cout << "AND " << a + 1 << " " << b + 1 << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    vector<int> ans(n);
    int axb = get_xor(0, 1);
    int bxc = get_xor(1, 2);
    int aib = get_and(0, 1);
    int aic = get_and(0, 2);
    int bic = get_and(1, 2);
    int axc = axb ^ bxc;
    int s = aib * 2 + bic * 2 + aic * 2 + axb + axc + bxc;
    s /= 2;
    s -= bic * 2 + bxc;
    ans[0] = s;
    ans[1] = s ^ axb;
    ans[2] = s ^ axc;
    for(int i = 3; i < n; ++i) ans[i] = ans[0] ^ get_xor(0, i);
    cout << "! ";
    range(i, n) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}