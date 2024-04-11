#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = 5000;

int sp[MAXN + 1][MAXN + 1], cnt[MAXN + 1];
int l[MAXN + 1], r[MAXN + 1];

inline int get(int l, int r, int x) {
    if(l > r) return 0;
    return sp[x][r] - sp[x][l - 1];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
        for(j = l[i]; j <= r[i]; j++) {
            cnt[j]++;
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            sp[i][j] = sp[i][j - 1] + (cnt[j] == i);
        }
    }
    int tot = 0;
    for(i = 1; i <= n; i++) {
        tot += (cnt[i] > 0);
    }
    int ans = 0;
    for(i = 1; i < q; i++) {
        for(j = i + 1; j <= q; j++) {
            int a = max(l[i], l[j]), b = min(r[i], r[j]);
            int l1 = l[i], l2 = l[j], r1 = r[i], r2 = r[j];
            if(l1 > l2) {
                swap(l1, l2), swap(r1, r2);
            }
            if(a <= b) {
                if(r1 >= r2) {
                    ans = max(ans, tot - get(l1, l2 - 1, 1) - get(l2, r2, 2) - get(r2 + 1, r1, 1));
                }
                else {
                    ans = max(ans, tot - get(l1, l2 - 1, 1) - get(l2, r1, 2) - get(r1 + 1, r2, 1));
                }
            }
            else {
                ans = max(ans, tot - get(l1, r1, 1) - get(l2, r2, 1));
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}