

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
ll md = 1000000007;
int n, m;

int get(vector<int> &a, vector<int> &b) {
    int ans = INFi;
    for (int i = 0; i < m; ++i) {
        ans = min(ans, max(a[i], b[i]));
    }
    return ans;
}


vector<vector<int>> arr;

pair<int, int> check(int ans) {
    vector<vector<int>> ae (1 << m);
    range(i, n) {
        int cur = 0;
        range(j, m) {
            if (arr[i][j] >= ans) cur += 1 << j;
        }
        ae[cur].push_back(i);
    }
    range(i, 1 << m) {
        range(j, 1 << m) {
            if ((i | j) == ((1 << m) - 1) && !ae[i].empty() && !ae[j].empty()) {
                return {ae[i].front(), ae[j].front()};
            }
        }
    }
    return {-1, -1};
}

void solve() {
    cin >> n >> m;
    arr.resize(n);
    range(i, n) {
        arr[i].resize(m);
        range(j, m) cin >> arr[i][j];
    }
    int l = 0;
    int r = 1e9 + 1;
    while(r - l > 1) {
        int mid = (r + l ) /2;
        auto f = check(mid);
        if (f.first != -1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    auto f = check(l);
    cout << f.first + 1 << ' ' << f.second + 1;
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