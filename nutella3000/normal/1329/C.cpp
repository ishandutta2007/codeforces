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
 
const int inf = 1e9;
const int max_n = 2e6 + 2;

int n, m;
int a[max_n];


void solve() {
    cin >> n >> m;
    n = (1 << n) - 1; m = (1 << m) - 1;

    for(int i = 0;i < n;i++)
        cin >> a[i];


    vector<int> el[n + 1];
    int Min[n + 1];
    set<int> res_nums;
    ll sum = 0;

    for(int i = n - 1;i >= 0;i--) {
        int v_min = -inf;
        if (i * 2 + 1 < n && i < m / 2) chkmax(v_min, Min[i * 2 + 1]);
        if (i * 2 + 2 < n && i < m / 2) chkmax(v_min, Min[i * 2 + 2]);

        if (a[i] > v_min)
            el[i].emplace_back(a[i]);

        for(int ch = i * 2 + 1;ch <= i * 2 + 2;ch++) {
            if (ch < n) {
                for(int j : el[ch]) {
                    if (j > v_min)
                        el[i].emplace_back(j);
                }
                el[ch].clear();
            }
        }

        int q = el[i][0];
        for(int j : el[i])
            q = min(q, j);


        Min[i] = q;

        if (i < m) {
            sum += q;
            res_nums.emplace(q);
        }
    }

    cout << sum << endl;
    for(int i = n - 1;i >= 0;i--) {
        if (!res_nums.count(a[i])) cout << i + 1 << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}