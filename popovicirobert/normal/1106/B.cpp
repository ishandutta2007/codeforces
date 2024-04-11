#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

int a[MAXN + 1], c[MAXN + 1];
int pos[MAXN + 1];

bool cmp(int a, int b) {
    if(c[a] == c[b]) {
        return a < b;
    }
    return c[a] < c[b];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> c[i];
        pos[i] = i;
    }
    sort(pos + 1, pos + n + 1, cmp);
    int p = 1;
    while(m > 0) {
        m--;
        int t, d;
        cin >> t >> d;
        ll ans = 0;
        int mn = min(a[t], d);
        ans += 1LL * mn * c[t];
        a[t] -= mn;
        d -= mn;
        if(d > 0) {
            while(p <= n && d > 0) {
                mn = min(d, a[pos[p]]);
                a[pos[p]] -= mn;
                d -= mn;
                ans += 1LL * mn * c[pos[p]];
                p++;
            }
            p = max(p - 1, 1);
        }
        if(d > 0) {
            ans = 0;
        }
        cout << ans << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}