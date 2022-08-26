#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 5e5 + 1;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    set<int> s;
    vector<int> ans(n, INFi);
    range(i, n) a[i]--;
    range(i, n) {
        s.insert(a[i]);
        auto j = s.upper_bound(a[i]);
        if (j != s.end()) {
            ans[a[i]] = min(ans[a[i]], *j);
        }
    }
   for(int i = n - 2; i >= 0; --i) ans[i] = min(ans[i], ans[i+1]);
   int answer = n;
   sort(all(a));
   a.resize(unique(all(a))-a.begin());
   n = a.size();
   int j = 0;
   range(i, n) {
       while(j < n && a[j] != ans[a[i]]) j++;
       answer = min(answer, i + n - j);
   }
   cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}