#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int INF = 1e18;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, C;
    cin >> n >> C;
    vector<int> c(n), d(n), h(n), mx(C + 1);
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> d[i] >> h[i];
        mx[c[i]] = max(mx[c[i]], d[i] * h[i]);
    }
    for (int i = 1; i <= C; i++) {
        mx[i] = max(mx[i], mx[i - 1]);
        int cnt = 2;
        for (int j = 2 * i; j <= C; j += i) {
            mx[j] = max(mx[j], mx[i] * cnt);
            cnt++;
        }
    }
    int m;
    cin >> m;
    vector<int> D(m), H(m);
    for (int i = 0; i < m; i++) {
        cin >> D[i] >> H[i];
    }
    for (int j = 0; j < m; j++) {
        int val = D[j] * H[j];
        if (val >= mx.back()) {
            cout << -1 << ' ';
        } else {
            int l = 0, r = C + 1;
            while (r - l > 1) {
                int mid = (r + l) / 2;
                if (mx[mid] > val) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            cout << r << ' ';
        }
    }
    cout << endl;
    return 0;
}