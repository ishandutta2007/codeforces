#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 2005;

char mat[MAXN + 1][MAXN + 1];

int up[MAXN + 1][MAXN + 1], down[MAXN + 1][MAXN + 1];

int best[4 * MAXN + 1];
int n, m;

inline void refresh(int nod) {
    best[nod] = max(best[nod], max(best[2 * nod], best[2 * nod + 1]));
}

inline void solve_line(int nod, int l1, int l2, int l) {
    deque < pair <int, int> > deq_up, deq_down;
    best[nod] = 0;
    int j = 1, sz = 0;
    for(int i = 1; i <= m; i++) {
        if(sz == 0 && j <= m) {
            deq_up.push_back({min(l - l1 + 1, up[l][j]), j});
            deq_down.push_back({min(l2 - l, max(down[l][j] - 1, 0)), j});
            sz++, j++;
        }
        while(j <= m && deq_up.front().first + deq_down.front().first >= sz) {
            best[nod] = max(best[nod], sz);

            int cur = min(l - l1 + 1, up[l][j]);
            while(deq_up.size() && deq_up.back().first >= cur) {
                deq_up.pop_back();
            }
            deq_up.push_back({cur, j});

            cur = min(l2 - l, max(0, down[l][j] - 1));
            while(deq_down.size() && deq_down.back().first >= cur) {
                deq_down.pop_back();
            }
            deq_down.push_back({cur, j});

            sz++, j++;
        }
        best[nod] = max(best[nod], min(sz, deq_up.front().first + deq_down.front().first));
        sz--;
        if(deq_up.front().second == i) {
            deq_up.pop_front();
        }
        if(deq_down.front().second == i) {
            deq_down.pop_front();
        }
    }
}

void build(int nod, int l1, int l2) {
    int mid = (l1 + l2) / 2;
    solve_line(nod, l1, l2, mid);
    if(l1 == l2) {
        return ;
    }
    build(2 * nod, l1, mid);
    build(2 * nod + 1, mid + 1, l2);
    refresh(nod);
}

void divide(int nod, int l1, int l2, int l) {
    int mid = (l1 + l2) / 2;
    solve_line(nod, l1, l2, mid);
    if(l1 == l2) {
        return ;
    }
    if(l <= mid)
        divide(2 * nod, l1, mid, l);
    if(mid < l)
        divide(2 * nod + 1, mid + 1, l2, l);
    refresh(nod);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) {
        cin >> mat[i] + 1;
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(mat[i][j] == '.') {
                up[i][j] = 1 + up[i - 1][j];
            }
        }
    }
    for(i = n; i >= 1; i--) {
        for(j = 1; j <= m; j++) {
            if(mat[i][j] == '.') {
                down[i][j] = 1 + down[i + 1][j];
            }
        }
    }
    build(1, 1, n);
    while(k > 0) {
        k--;
        int l, c;
        cin >> l >> c;
        i = l;
        while(i > 0 && mat[i][c] == '.') {
            down[i][c] = l - i;
            i--;
        }
        i = l;
        while(i <= n && mat[i][c] == '.') {
            up[i][c] = i - l;
            i++;
        }
        mat[l][c] = '#';
        divide(1, 1, n, l);
        cout << best[1] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}