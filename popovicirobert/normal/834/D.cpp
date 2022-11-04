#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 35000;
const int INF = (int) 1e9;

int v[MAXN + 1];

int dp1[MAXN + 1], dp2[MAXN + 1];
int last[MAXN + 1], nxt[MAXN + 1];

struct Aint {
    int val;
    int lazy;
}aint[4 * MAXN + 1];

inline void prop(int nod) {
    if(2 * nod + 1 <= 4 * MAXN) {
        aint[2 * nod].lazy += aint[nod].lazy;
        aint[2 * nod + 1].lazy += aint[nod].lazy;
    }
}

inline void solve_lazy(int nod) {
    prop(nod);
    aint[nod].val += aint[nod].lazy;
    aint[nod].lazy = 0;
}

void build(int nod, int left, int right) {
    aint[nod].lazy = 0;
    if(left == right)
        aint[nod].val = dp1[left];
    else {
        int med = (left + right) / 2;
        build(2 * nod, left, med);
        build(2 * nod + 1, med + 1, right);
        aint[nod].val = std::max(aint[2 * nod].val, aint[2 * nod + 1].val);
    }
}


void update(int nod, int left, int right, int l, int r) {
    solve_lazy(nod);
    if(l <= left && right <= r) {
        aint[nod].lazy++;
        solve_lazy(nod);
    }
    else {
        int med = (left + right) / 2;
        if(l <= med)
            update(2 * nod, left, med, l, r);
        if(med < r)
            update(2 * nod + 1, med + 1, right, l, r);
        solve_lazy(2 * nod);
        solve_lazy(2 * nod + 1);
        aint[nod].val = std::max(aint[2 * nod].val, aint[2 * nod + 1].val);
    }
}

int query(int nod, int left, int right, int l, int r) {
    solve_lazy(nod);
    if(l <= left && right <= r)
        return aint[nod].val;
    else {
        int med = (left + right) / 2;
        int val = -INF;
        if(l <= med)
            val = std::max(val, query(2 * nod, left, med, l, r));
        if(med < r)
            val = std::max(val, query(2 * nod + 1, med + 1, right, l, r));
        return val;
    }
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    for(i = 1; i <= n; i++) {
        dp1[i] = dp1[i - 1];
        nxt[i] = last[v[i]];
        if(last[v[i]] == 0)
            dp1[i]++;
        last[v[i]] = i;
    }
    for(i = 2; i <= k; i++) {
        build(1, 1, n);
        for(j = 1; j <= n; j++) {
            if(j < i)
                dp2[j] = -INF;
            else {
                update(1, 1, n, nxt[j], j - 1);
                dp2[j] = query(1, 1, n, i - 1, j - 1);
            }
        }
        for(j = 1; j <= n; j++)
            dp1[j] = dp2[j];
    }
    cout << dp1[n];
    //cin.close();
    //cout.close();
    return 0;
}