#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;
const int LOG = 16;

int arr[MAXN + 1];

struct Aint {
    int l, r;
}dp[LOG + 1][4 * MAXN + 1];

void update(int nod, int left, int right, int pos, int bit, pair <int, int> cur) {
    if(left > pos || right < pos) {
        return ;
    }
    if(left == right) {
        dp[bit][nod].l = cur.first;
        dp[bit][nod].r = cur.second;
    }
    else {
        int mid = (left + right) / 2;
        update(2 * nod, left, mid, pos, bit, cur);
        update(2 * nod + 1, mid + 1, right, pos, bit, cur);
        if(dp[bit][nod].l > cur.first) {
            dp[bit][nod].l = cur.first;
        }
        if(dp[bit][nod].r < cur.second) {
            dp[bit][nod].r = cur.second;
        }
    }
}

pair <int, int> query(int nod, int left, int right, int l, int r, int bit) {
    if(l <= left && right <= r) {
        return {dp[bit][nod].l, dp[bit][nod].r};
    }
    else {
        int mid = (left + right) / 2;
        pair <int, int> a = {MAXN, 0}, b = {MAXN, 0};
        if(l <= mid)
            a = query(2 * nod, left, mid, l, r, bit);
        if(mid < r)
            b = query(2 * nod + 1, mid + 1, right, l, r, bit);
        return {min(a.first, b.first), max(a.second, b.second)};
    }
}


inline void refresh(pair <int, int> &cur, pair <int, int> aux, int l, int r) {
    cur.first = min(cur.first, aux.first + l);
    cur.second = max(cur.second, aux.second + r);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);
    scanf("%d" ,&n);
    for(i = 1; i <= n; i++) {
        scanf("%d" ,&arr[i]);
    }
    if(n == 1) {
        printf("0");
        return 0;
    }
    for(int bit = 0; (1 << bit) <= n; bit++) {
        for(i = 1; i <= 4 * n; i++) {
            dp[bit][i].l = MAXN;
        }
    }
    for(i = 1; i <= n; i++) {
        update(1, 1, n, i, 0, {i - arr[i], i + arr[i]});
    }
    for(int bit = 1; (1 << bit) <= n; bit++) {
        for(i = 1; i <= n; i++) {
            pair <int, int> cur1 = query(1, 1, n, i, i, bit - 1);
            pair <int, int> cur2 = {3 * MAXN, -3 * MAXN};
            if(cur1.second - cur1.first + 1 >= n) {
                update(1, 1, n, i, bit, {1, n});
            }
            else {
                if(cur1.first > 0) {
                    refresh(cur2, query(1, 1, n, cur1.first, i, bit - 1), 0, 0);
                }
                else {
                    refresh(cur2, query(1, 1, n, 1, i, bit - 1), 0, 0);
                    refresh(cur2, query(1, 1, n, n + cur1.first, n, bit - 1), -n, -n);
                }
                if(cur1.second <= n) {
                    refresh(cur2, query(1, 1, n, i, cur1.second, bit - 1), 0, 0);
                }
                else {
                    refresh(cur2, query(1, 1, n, i, n, bit - 1), 0, 0);
                    refresh(cur2, query(1, 1, n, 1, cur1.second - n, bit - 1), n, n);
                }
                update(1, 1, n, i, bit, cur2);
            }
        }
    }
    for(i = 1; i <= n; i++) {
        int l = i, r = i;
        int ans = 0;
        for(int bit = LOG; bit >= 0; bit--) {
            if((1 << bit) > n) {
                continue;
            }
            pair <int, int> cur = {3 * MAXN, -3 * MAXN};
            if(l > 0) {
                refresh(cur, query(1, 1, n, l, i, bit), 0, 0);
            }
            else {
                refresh(cur, query(1, 1, n, 1, i, bit), 0, 0);
                refresh(cur, query(1, 1, n, n + l, n, bit), -n, -n);
            }
            if(r <= n) {
                refresh(cur, query(1, 1, n, i, r, bit), 0, 0);
            }
            else {
                refresh(cur, query(1, 1, n, i, n, bit), 0, 0);
                refresh(cur, query(1, 1, n, 1, r - n, bit), n, n);
            }
            if(cur.second - cur.first + 1 < n) {
                ans += (1 << bit);
                l = cur.first;
                r = cur.second;
            }
        }
        printf("%d " ,ans + 1);
    }
    //cin.close();
    //cout.close();
    return 0;
}