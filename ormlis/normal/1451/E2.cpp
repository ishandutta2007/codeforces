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

int get_or(int a, int b) {
    cout << "OR " << a + 1 << " " << b + 1 << endl;
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
    vector<int> xors(n), ans(n);
    vector<int> used(n, -1);
    used[0] = 0;
    bool finded = false;
    for (int i = 1; i < n; ++i) {
        xors[i] = get_xor(0, i);
        if (used[xors[i]] != -1 && !finded) {
            ans[i] = get_and(used[xors[i]], i);
            ans[0] = xors[i] ^ ans[i];
            finded = true;
        }
        used[xors[i]] = i;
    }
    if (!finded) {
        int j = used[1];
        int el = get_and(0, j);
        int e = 1;
        if (e == j) e++;
        if (xors[e] % 2 == 0) {
            int w = get_and(0, e);
            if (w % 2) ans[0] = el ^ 1;
            else ans[0] = el;
        } else {
            int w = get_and(j, e);
            if (w % 2) ans[0] = el;
            else ans[0] = el ^ 1;
        }
    }
    cout << "! ";
    range(i, n) cout << (ans[0] ^ xors[i]) << " ";
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