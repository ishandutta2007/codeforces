#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 400000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;

// double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k; cin >> n >> k;
    queue<int> q;
    unordered_set<int> s;
    range(i, n) {
        int id; cin >> id;
        if (s.count(id)) continue;
        if (q.size() == k) {
            s.erase(q.front());
            q.pop();
        }
        q.push(id);
        s.insert(id);
    }
    cout << q.size() << '\n';
    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
    }
    reverse(all(ans));
    for(auto &x: ans) cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}