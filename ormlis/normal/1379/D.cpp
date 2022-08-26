#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;


const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; int h, m, k; cin >> n >> h >> m >> k;
    vector<pair<int, int>> vo(n);
    range(i, n) cin >> vo[i].first >> vo[i].second;
    vector<int> times;
    range(i, n) {
        times.push_back(vo[i].second);
        if (vo[i].second < m / 2) {
            times.push_back(vo[i].second + m / 2);
        } else {
            times.push_back(vo[i].second - m / 2);
        }
    }
    sort(all(times));
    int len = m / 2 - k;
    int l = 0;
    pair<int, pair<int, int>> ans = {0, {0, 0}};
    range(r, times.size()) {
        while(times[r] - times[l] > len) {
            l++;
        }
        ans = max(ans, {r - l + 1, {l, r}});
    }
    int start = times[ans.second.first] % (m / 2);
    cout << n - ans.first << " " << start << "\n";
    vector<int> answers;
    range(i, n) {
        if (m - vo[i].second + start < k) {
            answers.push_back(i);
            continue;
        }
        if (start > vo[i].second && start - k < vo[i].second)  {
            answers.push_back(i);
            continue;
        }
        if (start + m / 2 > vo[i].second && start + m / 2 - k < vo[i].second) {
            answers.push_back(i);
            continue;
        }
    }
    for(auto &x: answers) cout << x + 1 << " ";
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