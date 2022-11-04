#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 2e5;

int v[MAXN + 1];

char aint[4 * MAXN + 1][101];

inline void prop(int a, int b) {
    if(b <= 4 * MAXN) {
        for(int i = 1; i <= 100; i++)
            aint[b][i] = aint[a][aint[b][i]];
    }
}

inline void solve_lazy(int nod) {
    prop(nod, 2 * nod);
    prop(nod, 2 * nod + 1);
    for(int i = 1; i <= 100; i++)
        aint[nod][i] = i;
}

void update(int nod, int left, int right, int l, int r, int a, int b) {
    if(l <= left && right <= r) {
        for(int i = 1; i <= 100; i++) {
            if(aint[nod][i] == a)
                aint[nod][i] = b;
        }
    }
    else {
        solve_lazy(nod);
        int med = (left + right) / 2;
        if(l <= med)
            update(2 * nod, left, med, l, r, a, b);
        if(med < r)
            update(2 * nod + 1, med + 1, right, l, r, a, b);
    }
}

void solve(int nod, int left, int right) {
    if(left == right) {
        cout << (int) aint[nod][v[left]] << " ";
    }
    else {
        solve_lazy(nod);
        int med = (left + right) / 2;
        solve(2 * nod, left, med);
        solve(2 * nod + 1, med + 1, right);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j, q;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(i = 1; i <= 4 * MAXN; i++) {
        for(j = 1; j <= 100; j++) {
            aint[i][j] = j;
        }
    }
    cin >> q;
    while(q > 0) {
        q--;
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        update(1, 1, n, l, r, a, b);
    }
    solve(1, 1, n);
    //cin.close();
    //cout.close();
    return 0;
}