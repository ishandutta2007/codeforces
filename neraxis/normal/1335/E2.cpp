#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

vector<int> cnt[205];
int a[N];
vector<int> v[205];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= 200; i++) {
        cnt[i].resize(n + 1, 0);
        v[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[a[i]].pb(i);
        for (int j = 1; j <= 200; j++) {
            cnt[j][i] = cnt[j][i - 1] + (a[i] == j);
        }
    }
    int ans = 0;
    for (int i = 1; i <= 200; i++) {
        ans = max(ans, (int) v[i].size());
        for (int j = 1; j <= v[i].size() / 2; j++) {
            int l = v[i][j - 1];
            int r = v[i][v[i].size() - j];
            // cout << i << ' ' << j << ' ' << l << ' ' << r << endl;
            //cout << l << ' ' << r << endl;
            for (int k = 1; k <= 200; k++) {
                if (k == i) continue;
                int bonus = cnt[k][r] - cnt[k][l];
                ans = max(ans, bonus + 2 * j);
            }
        }
    }
    cout << ans << '\n';
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        solve();
    }
    return 0;
}