#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

int n, k;
int suff[N];
int a[N];
int c[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) suff[a[i]]++;
    for (int i = k; i >= 1; i--) {
        suff[i] = suff[i + 1] + suff[i];
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        int foo = suff[i] / c[i] + (suff[i] % c[i] > 0);
        ans = max(ans, foo);
    }
    cout << ans << endl;
    vector<vector<int>> res;
    res.resize(ans + 1);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= ans; i++) pq.push({0, i});
    sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        ii u = pq.top(); pq.pop();
        res[u.y].pb(a[i]);
        pq.push({res[u.y].size(), u.y});
    }
    for (int i = 1; i <= ans; i++) {
        cout << res[i].size() << ' ';
        for (int e : res[i]) cout << e << ' ';
        cout << endl;
    }
    return 0;
}