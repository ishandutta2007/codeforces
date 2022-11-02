#include <bits/stdc++.h>
 
using namespace std;
 
#define aidar asadulin
 
//#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;
const int max_n = 1e6 + 3, log_n = 21;

ll solve(vector<int> a) {
    int n = sz(a);
    for(int i = 0;i < n;i++)
        a.emplace_back(a[i]);

    vector<int> nxt(sz(a), inf);

    deque<int> deq;

    for(int i = sz(a) - 1;i >= 0;i--) {
        while(sz(deq) && a[deq.back()] < a[i]) deq.pop_back();
        if (sz(deq)) nxt[i] = deq.back();
        deq.emplace_back(i);
    }

    vector<vector<int>> p(log_n, vector<int>(sz(a)));

    for(int i = 0;i < sz(a);i++)
        p[0][i] = nxt[i];

    for(int i = 1;i < log_n;i++) {
        for(int j = 0;j < sz(a);j++) {
            p[i][j] = (p[i - 1][j] == inf ? inf : p[i - 1][p[i - 1][j]]);
        }
    }

    ll res = 0;
    for(int i = 0;i < n;i++) {
        int cnt = 1, v = i + 1;

        for(int j = log_n - 1;j >= 0;j--) {
            if (p[j][v]  >= i + n || a[p[j][v]] > a[i]) continue;
            v = p[j][v];
            cnt += (1 << j);
        }
        if (a[v] <= a[i] && nxt[v] < i + n) {
            cnt++;
            v = nxt[v];
        }

        //cout << i << " " << v << " " << cnt << endl;

        res += cnt;

    }

    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++)
        cin >> a[i];

    ll res = solve(a);

    int max1 = -inf, max2 = -inf, cnt1 = 0, cnt2 = 0;

    for(int i : a) {
        if (i == max2) {
            cnt2++;
        }else if (i == max1) {
            cnt1++;
        }else if (i > max1) {
            cnt2 = cnt1;
            max2 = max1;
            max1 = i;
            cnt1 = 1;
        }else if (i > max2) {
            max2 = i;
            cnt2 = 1;
        }
    }

    if (cnt1 >= 2)
        res -= (ll)cnt1 * (cnt1 - 1) / 2;
    else 
        res -= cnt2;

    cout << res << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}