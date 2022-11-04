#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int B = 31;
const int MAXN = (int) 5e5 + 5;

char s[MAXN + 1], t[MAXN + 1];

ull hsh1[MAXN + 1], hsh2[MAXN + 1];
ull pw[MAXN + 1];

inline ull get1(int l, int r) {
    return hsh1[r] - hsh1[l - 1] * pw[r - l + 1];
}

inline ull get2(int l, int r) {
    return hsh2[r] - hsh2[l - 1] * pw[r - l + 1];
}

pair <int, int> lpos[4 * MAXN + 1], rpos[4 * MAXN + 1];

inline void solve_lazy(int nod, pair <int, int> *aint) {
    if(2 * nod + 1 <= 4 * MAXN) {
        aint[2 * nod].second = min(aint[nod].second, aint[2 * nod].second);
        aint[2 * nod + 1].second = min(aint[nod].second, aint[2 * nod + 1].second);
    }
    aint[nod].first = min(aint[nod].first, aint[nod].second);
    aint[nod].second = MAXN + 1;
}

void update(int nod, int left, int right, int l, int r, int val, pair <int, int> *aint) {
    solve_lazy(nod, aint);
    if(l <= left && right <= r) {
        aint[nod].second = min(aint[nod].second, val);
        solve_lazy(nod, aint);
    }
    else {
        int mid = (left + right) / 2;
        if(l <= mid)
            update(2 * nod, left, mid, l, r, val, aint);
        if(mid < r)
            update(2 * nod + 1, mid + 1, right, l, r, val, aint);
    }
}

int query(int nod, int left, int right, int pos, pair <int, int> *aint) {
    solve_lazy(nod, aint);
    if(left == right) {
        return aint[nod].first;
    }
    else {
        int mid = (left + right) / 2;
        if(pos <= mid)
            return query(2 * nod, left, mid, pos, aint);
        else
            return query(2 * nod + 1, mid + 1, right, pos, aint);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, k, i;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    cin >> s + 1;
    cin >> t + 1;
    for(i = 1; i <= n; i++) {
        hsh1[i] = hsh1[i - 1] * B + s[i] - 'a' + 1;
    }
    for(i = 1; i <= m; i++) {
        hsh2[i] = hsh2[i - 1] * B + t[i] - 'a' + 1;
    }
    pw[0] = 1;
    for(i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * B;
    }
    for(i = 1; i <= 4 * m; i++) {
        lpos[i] = rpos[i] = {MAXN + 1, MAXN + 1};
    }
    for(i = 1; i <= n; i++) {
        int res = 0;
        for(int step = 1 << 18; step; step >>= 1) {
            if(res + step <= min(m, k) && i + res + step - 1 <= n && get1(i, i + res + step - 1) == get2(1, res + step))
                res += step;
        }
        //printf("%d %d\n" ,k - i + 1, res);
        if(res == m) {
            int first = max(1, i + res - k), last = min(n - k + 1, i);
            if(first + k - 1 < n - k + 1) {
                cout << "Yes" << "\n";
                cout << first << " " << n - k + 1;
                return 0;
            }
            if(k < last) {
                cout << "Yes" << "\n";
                cout << 1 << " " << last;
                return 0;
            }
        }
        if(res >= k - i + 1)
            update(1, 0, m, max(0, k - i + 1), res, i, lpos);
    }
    for(i = n; i >= 1; i--) {
        int res = 0;
        for(int step = 1 << 18; step; step >>= 1) {
            if(res + step <= min(m, k) && i - res - step + 1 > 0 && get1(i - res - step + 1, i) == get2(m - res - step + 1, m))
                res += step;
        }
        //printf("%d %d\n" ,i - n + k,res);
        if(res >= i - n + k)
            update(1, 0, m, max(0, i - n + k), res, -i, rpos);
    }
    for(i = 1; i < m; i++) {
        int a = query(1, 0, m, i, lpos);
        int b = -query(1, 0, m, m - i, rpos);
        //printf("%d %d\n" ,a,b);
        if(a <= MAXN && b >= -MAXN && i > 0 && i < m) {
            if(a + i - 1 < b - (m - i) + 1) {
                cout << "Yes" << "\n";
                cout << a + i - k << " " << b - (m - i) + 1;
                return 0;
            }
        }
    }
    cout << "No";
    //cin.close();
    //cout.close();
    return 0;
}