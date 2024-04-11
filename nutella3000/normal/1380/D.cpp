#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, x, k, y;
    cin >> n >> m >> x >> k >> y;
    vector<int> a(n + 2), b(m + 1);
    map<int, int> finder;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        finder[a[i]] = i;
    }
    finder[0] = n + 1;

    int res = 0;

    bool bad = false;
    int last = 0;

    for(int q = 0;q <= m;q++) {
        if (q == m) b[q] = 0;
        else cin >> b[q];

        int v_id;
        if (finder.find(b[q]) == finder.end()) bad = true;
        else v_id = finder[b[q]];
        if (v_id <= last) bad = true;
        if (bad) break;

        int Max = 0;
        for(int i = last + 1;i < v_id;i++) Max = max(a[i], Max);

        int sz = v_id - last - 1;
        if (sz < k) if (Max > max(a[v_id], a[last])) bad = true;

        if (bad) break;

        if (x < y * k) {
            res += y * (sz % k) + x * (sz / k);
        }else{
            if (Max < max(a[v_id], a[last])) res += y * sz;
            else res += x + y * (sz - k);
        }

        last = v_id;
    }
    if (bad) cout << -1;
    else cout << res;
    cout << endl;
}