#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <cstring>
#include <map>
#include <bitset>
#include <iomanip>

#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const int Nm=100001;

int a[Nm], b[Nm];
vector<pair<int, int>> requests;
map<int, pair<int, int>> lr;

void solve() {
    int n, m; cin >> n >> m;
    range(i, n) cin >> a[i];
    range(i, n) cin >> b[i];
    lr[0] = {n - 1, 0};
    range(i, m) {
        int t; cin >> t;
        if(--t) {
            int x; cin >> x;
            int j = (--lr.upper_bound(x - 1))->second.second;
            if (j) {
                cout << a[requests[j - 1].first + x - requests[j - 1].second - 1] << '\n';
            } else {
                cout << b[x - 1] << '\n';
            }
        } else {
            int x, y, k; cin >> x >> y >> k;
            requests.emplace_back(x, y);
            int l = y - 1; int r = y - 2 + k;
            auto it = --lr.upper_bound(y - 1);
            if (it->second.first > r) {
                lr[r + 1] = it->second;
            }
            if (it->first < l) {
                it->second.first = l - 1;
                it++;
            } else {
                auto it2 = it; it++;
                lr.erase(it2);
            }
            while (it != lr.end() && it->second.first <= r) {
                auto it2 = it; it++;
                lr.erase(it2);
            }
            if (it != lr.end() && it->first <= r) {
                lr[r + 1] = it->second; lr.erase(it);
            }
            lr[l] = {r, requests.size()};
        }
    }
}


int main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tests; tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}