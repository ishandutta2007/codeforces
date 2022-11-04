#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

int v[MAXN + 1];
vector <int> pos[MAXN + 1];

int ind[MAXN + 1];

vector <int> aint[4 * MAXN + 1];

inline void refresh(int nod) {
    int n = aint[2 * nod].size(), m = aint[2 * nod + 1].size();
    aint[nod].clear();
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(aint[2 * nod][i] < aint[2 * nod + 1][j]) {
            aint[nod].push_back(aint[2 * nod][i]);
            i++;
        }
        else {
            aint[nod].push_back(aint[2 * nod + 1][j]);
            j++;
        }
    }
    while(i < n) {
        aint[nod].push_back(aint[2 * nod][i]);
        i++;
    }
    while(j < m) {
        aint[nod].push_back(aint[2 * nod + 1][j]);
        j++;
    }
}

void build(int nod, int left, int right) {
    if(left == right)
        aint[nod].push_back(ind[left]);
    else {
        int med = (left + right) / 2;
        build(2 * nod, left, med);
        build(2 * nod + 1, med + 1, right);
        refresh(nod);
    }
}

int ans = 0;

void query(int nod, int left, int right, int l, int r) {
    if(l <= left && right <= r) {
        int rez = -1;
        for(int pas = 1 << 16; pas; pas >>= 1)
            if(rez + pas < aint[nod].size() && aint[nod][rez + pas] < l)
               rez += pas;
        ans += rez + 1;
    }
    else {
        int med = (left + right) / 2;
        if(l <= med)
            query(2 * nod, left, med, l, r);
        if(med < r)
            query(2 * nod + 1, med + 1, right, l, r);
    }
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, y, q, j, k, l, r;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]].push_back(i);
    }
    for(i = 1; i <= MAXN; i++)
        for(j = 0; j < pos[i].size(); j++) {
            if(j >= k)
                ind[pos[i][j]] = pos[i][j - k];
            else
                ind[pos[i][j]] = -1;
        }
    build(1, 1, n);
    cin >> q;
    int last = 0;
    for(i = 1; i <= q; i++) {
        cin >> x >> y;
        l = (x + last) % n + 1;
        r = (y + last) % n + 1;
        if(l > r)
            swap(l, r);
        ans = 0;
        query(1, 1, n, l, r);
        cout << ans << endl;
        last = ans;
    }
    //cin.close();
    //cout.close();
    return 0;
}