#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 500;
const int S = 499;
const int D = 500;

bool exam[MAXN + 1];

int cap[MAXN + 1][MAXN + 1];
int flx[MAXN + 1][MAXN + 1];

vector <int> g[MAXN + 1];

inline void addEdge(int x, int y, int c) {
    g[x].push_back(y);
    cap[x][y] = c;
    g[y].push_back(x);
}

int from[MAXN + 1];
int q[MAXN + 1];

bool vis[MAXN + 1];

inline bool bfs() {
    int b = 0, e = 1;
    memset(vis, 0, sizeof(vis));
    q[0] = S;
    vis[S] = 1;
    while(b < e) {
        int nod = q[b];
        for(auto it : g[nod]) {
            if(vis[it] == 0 && flx[nod][it] < cap[nod][it]) {
                q[e++] = it;
                from[it] = nod;
                vis[it] = 1;
            }
        }
        b++;
    }
    return vis[D];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, s, d, c, j;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int sum = 0;
    for(i = 1; i <= m; i++) {
        cin >> s >> d >> c;
        sum += c;
        exam[d] = 1;
        addEdge(S, i, c);
        for(j = s; j < d; j++) {
            addEdge(i, j + n, 1);
        }
    }
    for(i = 1; i <= n; i++) {
        if(exam[i] == 0) {
            addEdge(i + n, D, 1);
        }
    }
    int ans = 0;
    while(bfs()) {
        int nod = D;
        int mn = 1e9;
        while(nod != S) {
            mn = min(cap[from[nod]][nod] - flx[from[nod]][nod], mn);
            nod = from[nod];
        }
        nod = D;
        while(nod != S) {
            flx[from[nod]][nod] += mn;
            flx[nod][from[nod]] -= mn;
            nod = from[nod];
        }
        ans += mn;
    }
    if(ans < sum) {
        cout << -1;
    }
    else {
        for(i = 1; i <= n; i++) {
            if(exam[i]) {
                cout << m + 1 << " ";
            }
            else {
                int mx = 0, id;
                for(j = 1; j <= m; j++) {
                    if(flx[j][i + n] == 1) {
                        mx = 1;
                        id = j;
                    }
                }
                if(mx == 0)
                    cout << 0 << " ";
                else
                    cout << id << " ";
            }
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}