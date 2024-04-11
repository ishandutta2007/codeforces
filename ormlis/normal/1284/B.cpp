#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>
#include <cmath>
#include <unordered_map>
#include <array>

#define ll long long
#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

const ll INF = 1e18;
const int maxN = 200001;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> s(n);
    range(i, n) {
        int l;
        cin >> l;
        s[i].resize(l);
        range(j, l) {
            cin >> s[i][j];
        }
    }
    vector<int> s2;
    vector<int> s3;
    ll ans = 0;
    ll ans2 = 0;
    range(i, n) {
        int mi = 1e9;
        int ma = 0;
        int flag = 0;
        range(j, s[i].size()) {
            mi = min(mi, s[i][j]);
            ma = max(ma, s[i][j]);
            if (s[i][j] > mi) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            s2.push_back(ma);
            s3.push_back(mi);
        }
        else ans2++;
    }
    sort(all(s2));
    reverse(all(s2));
    s2.push_back(-1);
    sort(all(s3));
    reverse(all(s3));
    int j = 0;
    for(auto x: s3) {
        while(j < s2.size() && s2[j] > x) {
            j++;
        }
        ans += j;
    }
    cout << ans2 * n + ans + (n - ans2) * ans2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    //cin >> tests;
    tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}