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
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 3e5 + 100;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

void solve() {
    int n, k, m, a;
    cin >> n >> k >> m >> a;
    vector<int> s(n), last(n, 101);
    range(i, a) {
        int f;
        cin >> f;
        f--;
        s[f]++;
        last[f] = i;
    }
    int f = 0;
    range(i, n) if (s[i]) f++;
    k = min(f + m - a, k);
    range(i, n) {
        int t = k;
        int t2 = k;
        vector<int> d;
        range(j, n) {
            if (i == j) continue;
            if (m - a == 0) {
                if (s[j] > s[i]) t2--;
                if (s[j] == s[i] && last[j] < last[i]) t2--;
            } else if (s[j] >= s[i] + m - a) t2--;
            if (s[j] > s[i]) t--;
            else if (s[j] == s[i] && last[j] < last[i]) t--;
            else {
                d.push_back(s[j]);
            }
        }
        if (t2 <= 0) {
            cout << "3 ";
            continue;
        }
        sort(rall(d));
        int am = m - a;
        for (auto &x: d) {
            int w = s[i] + 1 - x;
            if (w > am) break;
            am -= w;
            t--;
        }
        if (t > 0 && s[i]) cout << "1 ";
        else cout << "2 ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}