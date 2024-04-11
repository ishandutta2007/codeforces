#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e6 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> ab(n), cd(m);
    range(i, n) cin >> ab[i].first >> ab[i].second;
    range(i, m) cin >> cd[i].first >> cd[i].second;
    vector<pair<int, int>> nxt;
    sort(all(cd));
    for(int i = 0; i < m; ++i) {
        cd[i].first++; cd[i].second++;
        while(!nxt.empty() && nxt.back().second <= cd[i].second) {
            nxt.pop_back();
        }
        nxt.push_back(cd[i]);
    }
    cd = nxt;
    m = cd.size();
    vector<ar<int, 3>> vozm;
    range(i, n) {
        range(j, m) {
            if (cd[j].first >= ab[i].first) {
                vozm.push_back({0, max(0, cd[j].second - ab[i].second), i});
                break;
            }
        }
        for(int j = m - 1; j >= 0; --j) {
            if (cd[j].second >= ab[i].second) {
                vozm.push_back({max(cd[j].first - ab[i].first, 0), 0, i});
                break;
            }
        }
        range(j, m-1) {
            vozm.push_back({max(0, cd[j].first - ab[i].first), max(0, cd[j+1].second - ab[i].second), i});
        }
        range(j, 1) vozm.push_back({max(0, cd[j].first - ab[i].first), max(0, cd[j].second - ab[i].second), i});
    }
    sort(all(vozm));
    vector<int> mny(n, INFi);
    multiset<int> s;
    range(i, n) s.insert(INFi);
    int ans = INFi;
    for(auto &p: vozm) {
        if (mny[p[2]] > p[1]) {
            s.erase(s.find(mny[p[2]]));
            mny[p[2]] = min(mny[p[2]], p[1]);
            s.insert(mny[p[2]]);
        }
        int k = *s.rbegin();
        ans = min(ans, k + p[0]);
    }
    cout << ans << "\n";
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