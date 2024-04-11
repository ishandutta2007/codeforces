#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];

inline void bfs(int nod, vector <int> &dst) {
    queue <int> Q;
    dst[nod] = 1;
    Q.push(nod);

    while(Q.size()) {
        nod = Q.front();
        Q.pop();
        for(auto it : g[nod]) {
            if(dst[it] == 0) {
                Q.push(it);
                dst[it] = dst[nod] + 1;
            }
        }
    }

    for(int i = 1; i < dst.size(); i++) {
        dst[i]--;
    }
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, m, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    vector <int> a(k);
    for(i = 0; i < k; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector <int> dst1(n + 1), dstn(n + 1);
    bfs(1, dst1);
    bfs(n, dstn);

    int ans = dst1[n];

    sort(a.begin(), a.end(), [&](const int &x, const int &y) {
                return dst1[x] - dstn[x] < dst1[y] - dstn[y];
         });

    int best = 0, mx = 0;
    for(i = 0; i < k; i++) {
        if(i > 0) {
            best = max(best, dstn[a[i]] + mx + 1);
        }
        mx = max(mx, dst1[a[i]]);
    }

    cout << min(best, ans);

    return 0;
}