#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e10;
const int max_n = 1e5 + 1, max_p = 101;

int n, p;
int a[max_n], suf[max_n];
int dp[max_n][max_p];
deque<pii> line[max_p];

void scan() {
    int m;
    cin >> m >> n >> p;
    vector<int> d(m), h(n), t(n);
    for(int i = 1;i < m;i++) {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    for(int i = 0;i < n;i++) {
        cin >> h[i] >> t[i];
        h[i]--;
        a[i] = t[i] - d[h[i]];
    }

    sort(a, a + n);
    for(int i = n - 1;i >= 0;i--) {
        suf[i] = a[i] + suf[i + 1];
    }
}

ld intersection(pii a, pii b) {
    return (a.se - b.se) / (b.fi - a.fi);
}

void add(int id, pii a) {
    while(line[id].size() >= 2) {
        pii x1 = line[id].back();
        line[id].pop_back();
        if (intersection(x1, a) > intersection(line[id].back(), a)) {
            line[id].emplace_back(x1);
            break;
        }
    }
    line[id].emplace_back(a);
}

int get(int id, int x) {

    while(line[id].size() >= 2) {
        pii x1 = line[id].front();
        line[id].pop_front();
        pii x2 = line[id].front();
        if (x1.fi * x + x1.se < x2.fi * x + x2.se) {
            line[id].emplace_front(x1);
            break;
        }
    }
    return line[id].front().fi * x + line[id].front().se;
}

void solve() {
    scan();
    add(0, mp(1, -suf[0]));

    for(int i = 0;i < n;i++) {
        for(int j = p;j > 0;j--) {
            if (line[j - 1].empty()) continue;

            dp[i][j] = get(j - 1, a[i]) + suf[i] + (i - 1) * a[i];
            add(j, mp(-i, dp[i][j] - suf[i + 1]));

            //cout << i + 1 << " " << j << " " << dp[i][j] << endl;
        }
    }

    cout << dp[n - 1][p] << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}