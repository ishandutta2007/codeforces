#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 400000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;

// double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k;
    cin >> n >> k;
    vector<char> a2(n);
    range(i, n) cin >> a2[i];
    auto a = a2;
    int r = 0, l = 0;
    while(1) {
        vector<int>  w;
        range(i, n - 1) if (a[i] == 'R' && a[i + 1] == 'L') w.push_back(i);
        if (w.empty()) break;
        for(auto &i: w) {
            a[i] = 'L';
            a[i+1] = 'R';
        }
        r += (int)w.size();
        l += 1;
    }
    if (k < l || k > r) {
        cout << "-1\n";
        return;
    }
    a = a2;
    while(1) {
        l--;
        vector<int>  w;
        range(i, n - 1) if (a[i] == 'R' && a[i + 1] == 'L') w.push_back(i);
        if (w.empty()) break;
        for(auto &i: w) {
            a[i] = 'L';
            a[i+1] = 'R';
        }
        if (k - (int)w.size() >= l) {
            for(auto &i: w) cout << "1 " << i + 1 << "\n";
            k -= (int)w.size();
        } else {
            int z = k - l;
            range(i, z - 1) cout << "1 " << w[i] + 1 << "\n";
            cout << (int)w.size() - (z - 1) << ' ';
            for(int i = z - 1; i < (int)w.size(); ++i) cout << w[i] + 1 << " ";
            cout << "\n";
            k -= z;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}