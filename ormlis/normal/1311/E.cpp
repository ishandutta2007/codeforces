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

struct Node {
    int l=-1, r=-1, p=-1;
};

vector<Node> s;
vector<pair<int, int>> hi;

void solve() {
    int n, d; cin >> n >> d;
    s.clear();
    hi.clear();
    range(i, n) s.push_back({i+1, -1, i-1});
    range(i, n) hi.emplace_back(i, i);
    s.back().l=-1;
    int cur = (n -1) * n / 2;
    for(int i = n - 1; i >= 2; --i) {
        if (cur <= d) break;
        if (s[i].l != -1 || s[i].r != -1) continue;
        int ansj=-1, ansh=50000;
        for(auto p: hi) {
            int j = p.second;
            int h = p.first;
            if (s[j].l == -1 || s[j].r == -1) {
                if (i >= h && cur - (i - (h+1)) >= d && h <= ansh) {
                    ansh = h;
                    ansj = j;
                }
            }
        }
        if (ansj==-1) continue;
        if (s[s[i].p].l == i) {
            s[s[i].p].l = -1;
        } else {
            s[s[i].p].r = -1;
        }
        if (s[ansj].l == -1) {
            s[ansj].l = i;
        } else {
            s[ansj].r = i;
        }
        s[i].p = ansj;
        cur -= hi[i].first - (ansh+1);
        hi[i].first = ansh+1;
    }
    if (cur == d) {
        cout << "YES\n";
        for(int i = 1; i < n; ++i) {
            cout << s[i].p+1 << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}