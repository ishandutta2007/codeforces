#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e6;

vector < pair <int, int> > upd[MAXN + 5];
pair <ll, ll> aib[MAXN + 1];

inline void update(int pos, int n, ll s, int cnt) {
    for(int i = pos; i <= n; i += lsb(i)) {
        aib[i].first += s;
        aib[i].second += cnt;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k, m;
    ios::sync_with_stdio(false);
    cin >> n >> k >> m;
    for(i = 1; i <= m; i++) {
        int l, r, p, c;
        cin >> l >> r >> c >> p;
        upd[l].push_back({p, c});
        upd[r + 1].push_back({p, -c});
    }
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        for(auto it : upd[i]) {
            update(it.first, MAXN, 1LL * it.first * it.second, it.second);
        }
        int res = 0;
        ll sum = 0, cnt = 0;
        for(int step = 1 << 19; step; step >>= 1) {
            if(res + step <= MAXN && aib[res + step].second + cnt < k) {
                res += step;
                sum += aib[res].first;
                cnt += aib[res].second;
            }
        }
        ans += sum;
        res++;
        if(res <= MAXN) {
            ans += 1LL * (k - cnt) * res;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}