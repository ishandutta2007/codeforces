#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

int arr[100001];
map<int, int> ma;

void solve() {
    ll k;
    int n; cin >> n >> k;
    range(i, n) {
        cin >> arr[i];
        ma[arr[i]]++;
    }
    set<int> s;
    for(auto p: ma) {
        s.insert(p.first);
    }
    int cur1 = ma[*s.begin()], cur2 = ma[*s.rbegin()];
    ll ans = k;
    while (ans && s.size() > 1 && ans >= min(cur1, cur2)) {
        ll m = 0;
        ll op = 0;
        if (cur1 < cur2) {
            ll f = *s.begin();
            s.erase(f);
            m = min((*s.begin() - f) * cur1, ans);
            op = m - m % cur1;
            f += m / cur1;
            if (*s.begin() == f) {
                cur1 += ma[*s.begin()];
            } else {
                s.insert(f);
            }
        } else {
            ll f = *s.rbegin();
            s.erase(f);
            m = min((f - *s.rbegin()) * cur2, ans);
            f -= m / cur2;
            op = m - m % cur2;
            if (*s.rbegin() == f) {
                cur2 += ma[*s.rbegin()];
            } else {
                s.insert(f);
            }
        }
        ans -= op;
    }
    cout << *s.rbegin() - *s.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(i, tests) {
        solve();
    }
    return 0;
}