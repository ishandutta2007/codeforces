#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 1e6 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int fenw[maxN];
int n;

void upd(int i, int x) {
    for (; i <= n; i = i | (i + 1)) fenw[i] += x;
}

int get(int i) {
    int res = 0;
    for (; i > 0; i = (i & (i + 1)) - 1) res += fenw[i];
    return res;
}

int find(int k) {
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (get(mid) >= k) r = mid;
        else l = mid;
    }
    return r;
}

void solve() {
    int q;
    cin >> n >> q;
    range(i, n) {
        int x;
        cin >> x;
        upd(x, 1);
    }
    int bal = n;
    range(i, q) {
        int k;
        cin >> k;
        if (k > 0) {
            bal++;
            upd(k, 1);
        } else {
            bal--;
            upd(find(-k), -1);
        }
    }
    if (bal == 0) {
        cout << "0\n";
    } else {
        cout << find(1) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}