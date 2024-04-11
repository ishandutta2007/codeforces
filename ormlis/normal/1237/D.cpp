#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 400000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;

// double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    multiset<int> s;
    int mi = *min_element(all(a));
    int mx = *max_element(all(a));
    if ((mx + 1) / 2 <= mi) {
        range(i, n) cout << -1 << " ";
        return;
    }
    for(int i = 0, c = 0; i < n; ++i) {
        while(1) {
            if (s.empty()) {
                s.insert(a[(i + c) % n]);
                c++;
                continue;
            }
            int mxe = *s.rbegin();
            if ((mxe + 1) / 2 > a[(i + c) % n]) {
                break;
            }
            s.insert(a[(i + c) % n]);
            c++;
        }
        cout << c << " ";
        s.erase(s.find(a[i]));
        c--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}