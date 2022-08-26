#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1e5 * 2;
ll md = 1000000007;
int k = 0;
vector<pair<int, string>> ans;
void g(int s, string &t) {
    if (k == 0) {
        return;
    }
    if (s == 0) return;
    int f = (int)t.size() - 2;
    if (k < s * f) {
        int a = k / f;
        if (a) {
            ans.emplace_back(a, t);
        }
        int b = k % f;
        if (b) {
            ans.emplace_back(1, t.substr(0, b + 1) + "\n");
        }
        k = 0;
        return;
    }
    ans.emplace_back(s, t);
    k -= s * f;
}

void solve() {
    int n, m; cin >> n >> m >> k;
    if (4 * n * m - 2 * n - 2 * m < k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    string s1 = " DUR\n", s2 = " DUL\n", s3 = " R\n", s4 = " D\n", s5 =  " L\n", s6 = " U\n";
    range(i, n - 1) {
        if ((i & 1) == 0) {
            g(m - 1, s1);
        } else {
            g(m - 1, s2);
        }
        g(1, s4);
    }
    if (n & 1) {
        g(m - 1, s3);
        g(m - 1, s5);
    } else {
        g(m - 1, s5);
        g(m - 1, s3);
    }
    for(int i = n - 2; i >= 0; --i) {
        g(1, s6);
        if (i & 1) {
            g(m - 1, s3);
        } else {
            g(m - 1, s5);
        }
    }
    cout << ans.size() << "\n";
    for(auto p: ans) {
        cout << p.first << p.second;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}