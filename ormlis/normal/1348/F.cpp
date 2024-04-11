#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    range(i, n) cin >> a[i].first >> a[i].second;
    vector<int> p(n);
    vector<ar<int ,2>> s;
    range(i, n) {
        a[i].first--;
        a[i].second--;
        s.push_back({a[i].first, i});
    }
    sort(all(s));
    int j = 0;
    multiset<pair<int, int>> q;
    range(i, n) {
        while(j < n && s[j][0] <= i) {
            q.insert({a[s[j][1]].second, s[j][1]});
            j++;
        }
        auto b = *q.begin();
        q.erase(q.begin());
        p[b.second] = i;
    }

    vector<int> pos(n);
    range(i, n) pos[p[i]] = i;

    vector<vector<int>> need_to_del(n);
    range(i, n) {
        need_to_del[a[pos[i]].second].push_back(i);
    }

    set<int> sw;
    range(i, n) {
        auto it = sw.lower_bound(a[pos[i]].first);
        if (it != sw.end()) {
            cout << "NO\n";
            range(e, n) cout << p[e] + 1 << ' ';
            int w = *it;
            cout << '\n';
            swap(p[pos[i]], p[pos[w]]);
            range(e, n) cout << p[e] + 1 << ' ';
            return;
        }
        sw.insert(i);
        for(auto &x: need_to_del[i]) sw.erase(x);
    }
    cout << "YES\n";
    range(e, n) cout << p[e] + 1 << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}