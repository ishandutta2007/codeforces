// author: Monarchuwu, https://codeforces.com/contest/1661/submission/153206439

/**
 *  Problem:    CF1661F - Teleporters
 *  Link:       https://codeforces.com/contest/1661/problem/F
 *  Tags:       Binary Search
 *  Hints:      ...
 *  Solution:   ...
**/
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define ff first
#define ss second

const int N = 2e5 + 8;
int n;
ll a[N], m, M;
pair<ll, int> b[N];

<<<<<<< HEAD
// chia len thành k do?n
ll calc(int len, int k) {
    int lenk = len / k;
    int x = len - lenk * k; // lu?ng do?n d? dài len/k + 1
=======
// chia len thnh k do?n
ll calc(int len, int k) {
    int lenk = len / k;
    int x = len - lenk * k; // lu?ng do?n d? di len/k + 1
>>>>>>> ba48ae4a69f706fe86df6abfbbc02a36ff86f577
    return (ll)lenk * lenk * (k - x) + (ll)(lenk + 1) * (lenk + 1) * x;
}

pli solve(ll x) {
    ll sum(0);
    int cnt(0);
    for (int i = 0, len; i < M; ++i) {
        len = b[i].first;
        int lo(2), hi(len), mid;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            if (calc(len, mid - 1) - calc(len, mid) >= x)
                lo = mid + 1;
            else hi = mid - 1;
        }
        // lo-1 do?n
        sum += calc(len, lo - 1) * b[i].second;
        cnt += (lo - 2) * b[i].second;
    }
    return pli(sum, cnt);
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = n; i > 1; i--) a[i] -= a[i-1];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; M++) {
        int k = i;
        while (a[k] == a[i]) k++;
        b[M] = {a[i], k - i};
        i = k;
    }

    cin >> m;

    ll lo(1), hi(m), mid;
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (solve(mid).ff <= m)
            lo = mid + 1;
        else hi = mid - 1;
    }

    pli tmp = solve(lo - 1);
    cout << tmp.ss - (m - tmp.ff) / (lo - 1) << '\n';
    // ...
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/