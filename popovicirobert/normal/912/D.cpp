#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

int cntx[MAXN + 1], cnty[MAXN + 1];
int n, m;

ll cnt;
ll expected;

inline ll check(ll val) {
    int pos = m;
    ll sum = 0;
    cnt = expected = 0;
    for(int i = 1; i <= n; i++) {
        while(pos > 0 && 1LL * cnty[pos] * cntx[i] >= val) {
            sum += cnty[pos];
            pos--;
        }
        cnt += m - pos;
        expected += 1LL * sum * cntx[i];
    }
    return cnt;
}

map <ll, ll> mp;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, r, k;
    ios::sync_with_stdio(false);
    cin >> n >> m >> r >> k;
    for(i = 1; i <= n; i++) {
        cntx[i] = min(n, i + r - 1) - max(r, i) + 1;
    }
    for(i = 1; i <= m; i++) {
        cnty[i] = min(m, i + r - 1) - max(r, i) + 1;
    }
    sort(cntx + 1, cntx + n + 1);
    sort(cnty + 1, cnty + m + 1);
    ll res = 1LL * r * r + 1;
    for(ll step = 1LL << 50; step; step >>= 1) {
        if(check(res - step) < k)
            res -= step;
    }
    check(res);
    res--;
    for(i = 1; i <= m; i++) {
        mp[cnty[i]]++;
    }
    for(i = 1; i <= n; i++) {
        expected += res * min(k - cnt, mp[res / cntx[i]]);
        cnt += min(k - cnt, mp[res / cntx[i]]);
    }
    cout << fixed << setprecision(20) << 1.0 * expected / (1LL * (n - r + 1) * (m - r + 1));
    //cin.close();
    //cout.close();
    return 0;
}