#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    int k = 101;
    vector<int> cnt(k);
    int answer = 0;
    range(i, n) {
        cnt[a[i]]++;
        int mx = 0;
        int cmx = 0;
        range(j, k) {
            if (mx < cnt[j]) {
                mx = cnt[j];
                cmx = 0;
            }
            if (mx == cnt[j]) cmx++;
        }
        if (cmx > 1) {
            answer = i + 1;
            continue;
        }
    }
    if (answer == n) {
        cout << n << "\n";
        return;
    }
    int z = max_element(all(cnt)) - cnt.begin();
    cnt.assign(k, 0);
    vector<vector<int>> b(k);
    range(i, k) b[i].push_back(-1);
    range(i, n) {
        cnt[a[i]]++;
        range(j, k) {
            if (j == z) continue;
            if ((int) b[j].size() <= cnt[z] - cnt[j]) b[j].push_back(i);
            else if (i >= answer)
                answer = max(answer, i - b[j][cnt[z] - cnt[j]]);
        }
    }
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}