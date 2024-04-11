#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 100001;
ll md = 998244353;

bool check(int x) {
    cout << "> " << x << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    auto seed = chrono::system_clock::now().time_since_epoch().count();
    auto rng = mt19937(seed);
    int n;
    cin >> n;
    int l = n - 2, r = 1e9 + 1;
    int req = 0;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        req++;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int m = r;
    vector<int> reqst;
    range(i, n) {
        reqst.push_back(i);
    }
    range(_, 10) {
        shuffle(all(reqst), rng);
    }
    vector<int> f;
    f.push_back(m);
    for(int i = 0; i < n && i < 60 - req; ++i) {
        cout << "? " << reqst[i] + 1 << endl;
        int a;
        cin >> a;
        f.push_back(a);
    }
    sort(all(f));
    int d = f[1] - f[0];
    for (int i = 1; i < f.size(); ++i) {
        d = __gcd(d, f[i] - f[i - 1]);
    }
    cout << "! " << m - (n - 1) * d << " " << d;
}

int main() {
    /*
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
     */
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}