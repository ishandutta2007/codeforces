#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 80;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> ans1, ans2;
    int i = 0, j = n;
    while(i != j) {
        if (ans1.size() < ans2.size()) {
            if (s[i] == '(') {
                ans1.push_back(i+1);
            }
            i++;
        } else {
            j--;
            if (s[j] == ')') ans2.push_back(j+1);
        }
    }
    int f = min(ans1.size(), ans2.size());
    if (f == 0) cout << 0;
    else {
        cout << 1 << "\n" << f * 2 << "\n";
        range(i, f) {
            cout << ans1[i] << " ";
        }
        range(i, f) {
            cout << ans2[f-i-1] << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}