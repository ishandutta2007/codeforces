#include <bits/stdc++.h> 
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
int flow[55];
int n, m;
int l[11][11], h[11][11];
int c[11][11];
int cur;
int ans, cost;
vector < pair < int, int > > vec;
void run(int x) {
    if (flow[n - 1] > ans) return;
    if (x == vec.size()) {
        if (flow[n - 1] < ans || (flow[n - 1] == ans && cost < cur)) {
            ans = flow[n - 1];
            cost = cur;
        }
        return;
    }
    pair < int, int > e = vec[x];
    int f = e.first, s = e.second;
    int L = l[f][s], R = h[f][s];
    if (s == n - 1 && f != 0) {
        if (flow[f] < l[f][s] || flow[f] > h[f][s]) return;
        L = R = flow[f];
    }
    for (int i = L; i <= R; ++i) {
        if (i > flow[f]) break;
        flow[f] -= i;
        flow[s] += i;
        if (i != 0) {
            cur += c[f][s];
            cur += i * i;
        }
        run(x + 1);
        if (i != 0) {
            cur -= c[f][s];
            cur -= i * i;
        }
        flow[f] += i;
        flow[s] -= i;
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x, y, L, H, A;
            scanf("%d%d%d%d%d", &x, &y, &L, &H, &A);
            x--; y--;
            l[x][y] = L; h[x][y] = H;
            c[x][y] = A;
 
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vec.push_back(make_pair(i, j));
        }
    }
    flow[0] = 105;
    ans = 1005; cost = -1;
    run(0);
    if (ans == 1005) ans = -1;
    cout << ans << " " << cost << endl;
    return 0;
}