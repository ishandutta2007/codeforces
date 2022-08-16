#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e3+10, MOD = 1e9+7;

int n, one[MAXN], two[MAXN];
int ans[MAXN], cur[MAXN], cnt = 0;

int inv[MAXN];

bool hit[MAXN];
bool is_perm() {
    for (int i = 0; i < n; i++) hit[i] = 0;
    for (int i = 0; i < n; i++) {
        if (cur[i] < 0 || cur[i] >= n) return 0;
        hit[cur[i]] = 1;
    }
    for (int i = 0; i < n; i++) if (!hit[i]) return 0;
    return 1;
}
bool is_good() {
    if (!is_perm()) return 0;
    for (int i = 0; i < n; i++) inv[cur[i]] = i;
    for (int i = 0; i < n; i++) {
        if ((cur[0] ^ inv[i]) != one[i]) return 0;
        if ((cur[i] ^ inv[0]) != two[i]) return 0;
    }
    return 1;
}
int qry(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int x; cin >> x;
    return x;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) one[i] = qry(0, i);
    for (int i = 0; i < n; i++) two[i] = qry(i, 0);

    for (int a = 0; a < n; a++) {
        for (int i = 0; i < n; i++) cur[i] = two[i] ^ a;
        if (is_good()) {
            cnt++;
            for (int i = 0; i < n; i++) ans[i] = cur[i];
        }
    }
    cout << '!' << endl;
    cout << cnt << '\n';
    for (int i = 0; i < n; i++) cout << ans[i] << ' '; cout << '\n';
    cout.flush();
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}