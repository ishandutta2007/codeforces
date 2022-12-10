#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

const int maxn = 200 + 10;
int h[2][maxn],
    t[2][maxn],
    dis[maxn][maxn],
    mark[maxn][maxn],
    dp[maxn][maxn],
    n, m, R;

bool alive(int head, int tail) {
    return head + tail <= R;
}

void bfs(pii source) {
    memset(dis, 63, sizeof dis);
    dis[source.L][source.R] = 0;
    vector<pii> q;
    q.PB(source);
    for (int i = 0; i < sz(q); i++) {
        int head = q[i].L,
            tail = q[i].R;
        for (int j = 1; j <= n and j <= head; j++) {
            int nhead = head - j + h[0][j - 1];
            int ntail = tail + t[0][j - 1];
            if (alive(nhead, ntail) and dis[nhead][ntail] > dis[head][tail] + 1) {
                dis[nhead][ntail] = dis[head][tail] + 1;
                q.PB(pii(nhead, ntail));
            }
        }
        for (int j = 1; j <= m and j <= tail; j++) {
            int nhead = head + h[1][j - 1];
            int ntail = tail - j + t[1][j - 1];
            if (alive(nhead, ntail) and dis[nhead][ntail] > dis[head][tail] + 1) {
                dis[nhead][ntail] = dis[head][tail] + 1;
                q.PB(pii(nhead, ntail));
            }
        }
    }
    if (dis[0][0] > 1e9)
        return;
    cout << "Ivan\n"
        << dis[0][0] << '\n';
    exit(0);
}

void dfs(int curh, int curt) {
    dp[curh][curt] = 1;
    mark[curh][curt] = 1;
    for (int i = 1; i <= n and i <= curh; i++) {
        int nxth = curh - i + h[0][i - 1];
        int nxtt = curt + t[0][i - 1];
        if (!alive(nxth, nxtt)) continue;
        if (mark[nxth][nxtt] == 1) {
            cout << "Draw" << '\n';
            exit(0);
        }
        else if (mark[nxth][nxtt] == 0)
            dfs(nxth, nxtt);
        dp[curh][curt] = max(dp[curh][curt], dp[nxth][nxtt] + 1);
    }
    for (int i = 1; i <= m and i <= curt; i++) {
        int nxth = curh + h[1][i - 1];
        int nxtt = curt - i + t[1][i - 1];
        if (!alive(nxth, nxtt)) continue;
        if (mark[nxth][nxtt] == 1) {
            cout << "Draw" << '\n';
            exit(0);
        }
        else if (mark[nxth][nxtt] == 0)
            dfs(nxth, nxtt);
        dp[curh][curt] = max(dp[curh][curt], dp[nxth][nxtt] + 1);
    }
    mark[curh][curt] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int starth, startt;
    cin >> starth >> startt >> R;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[0][i] >> t[0][i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> h[1][i] >> t[1][i];
    bfs(pii(starth, startt));
    dfs(starth, startt);
    cout << "Zmey\n"
        << dp[starth][startt] << '\n';
    return 0;
}