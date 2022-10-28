#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e2+10, MOD = 1e9+7;

int n, k;
int a[N][N];
int cnt[N * N], tot_cnt[N * N];

void solve() {
    cin >> n >> k;
    set<int> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j], --a[i][j];
            tot_cnt[a[i][j]]++;
            s.insert(a[i][j]);
        }
    }
    if (k >= sz(s)) {
        cout << k - sz(s) << '\n';
        return;
    }
    for (int d = -(n-1); d <= n-1; d++) {
        // cells such that i - j == d
        int i = d <= 0 ? 0 : d;
        int j = i - d;
        ar<int, 2> p{i, j};
        memset(cnt, 0, sizeof(cnt));
        int cur_cnt = 0;
        for (; i < n && j < n; i++, j++) {
            while (p[0] < n && p[1] < n) {
                int my_add = 0;
                // i to p[0], j to p[1]
                for (int ni = i; ni <= p[0]; ni++) {
                    my_add += ((++cnt[a[ni][p[1]]]) == tot_cnt[a[ni][p[1]]]);
                }
                for (int nj = j; nj < p[1]; nj++) {
                    my_add += ((++cnt[a[p[0]][nj]]) == tot_cnt[a[p[0]][nj]]);
                }
                int cnt_only = cur_cnt + my_add;
                if (sz(s) - cnt_only == k || sz(s) - cnt_only + 1 == k) {
                    cout << 1 << '\n';
                    return;
                }
                if (sz(s) - cnt_only < k) {
                    for (int ni = i; ni <= p[0]; ni++) {
                        cnt[a[ni][p[1]]]--;
                    }
                    for (int nj = j; nj < p[1]; nj++) {
                        cnt[a[p[0]][nj]]--;
                    }
                    break;
                }
                cur_cnt += my_add;
                p[0]++, p[1]++;
            }

            if (p[0] > i && p[1] > j) {
                for (int ni = i; ni <= p[0]; ni++) {
                    cur_cnt -= ((cnt[a[ni][j]]--) == tot_cnt[a[ni][j]]);
                }
                for (int nj = j + 1; nj < p[1]; nj++) {
                    cur_cnt -= ((cnt[a[i][nj]]--) == tot_cnt[a[i][nj]]);
                }
            } else {
                p[0]++, p[1]++;
            }
        }
    }
    cout << 2 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}