#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

struct Edge {
    int x, y, c;
    bool operator <(const Edge &other) const {
        return c < other.c;
    }
}edge[MAXN + 1];

int x[MAXN + 1];
pair <int, int> res[MAXN + 1];
int sz[MAXN + 1], sef[MAXN + 1];
int n, m, k;

int myfind(int x) {
    if(sef[x] == 0)
        return x;
    return sef[x] = myfind(sef[x]);
}

inline void myunion(int x, int y) {
    x = myfind(x), y = myfind(y);
    if(x != y) {
        sef[x] = y;
        sz[y] += sz[x];
    }
}

inline void solve(int step) {
    int i;
    for(i = 1; i <= n; i++) {
        sz[i] = sef[i] = 0;
    }
    for(i = 1; i <= k; i++) {
        sz[x[i]] = 1;
    }
    sort(res + 1, res + n + 1);
    int pos = 1;
    for(i = 1; i <= n; i++) {
        while(pos <= m && edge[pos].c <= res[i].first + step) {
            myunion(edge[pos].x, edge[pos].y);
            pos++;
        }
        if(sz[myfind(res[i].second)] < k) {
            res[i].first += step;
        }
    }
}

int sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(i = 1; i <= k; i++) {
        cin >> x[i];
    }
    for(i = 1; i <= m; i++) {
        cin >> edge[i].x >> edge[i].y >> edge[i].c;
    }
    sort(edge + 1, edge + m + 1);
    for(i = 1; i <= n; i++) {
        res[i] = {0, i};
    }
    for(int step = 1 << 30; step; step >>= 1) {
        solve(step);
    }
    for(i = 1; i <= n; i++) {
        sol[res[i].second] = res[i].first + 1;
    }
    for(i = 1; i <= k; i++) {
        cout << sol[x[i]] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}