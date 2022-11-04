#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = (ll) 1e18 + 123;
const int N = (int) 1e3 + 10;
const int L = 26;
const int K = (int) 3e5 + 10;

struct Rect {
    int x1, x2, y1, y2, c;
};

int n, m, k;
int a[N][N];
ll cnt[N][N][L];
ll just[N][N];
Rect rect[K];

ll get(int x1, int y1, int x2, int y2, int c) {
    return cnt[x2][y2][c] - cnt[x1 - 1][y2][c] - cnt[x2][y1 - 1][c] + cnt[x1 - 1][y1 - 1][c];
}

ll get_j(int x1, int y1, int x2, int y2) {
    return just[x2][y2] - just[x1 - 1][y2] - just[x2][y1 - 1] + just[x1 - 1][y1 - 1];
}

ll calc(int q) {
    ll res = get_j(1, 1, n, m) - get_j(rect[q].x1, rect[q].y1, rect[q].x2, rect[q].y2);
    
    for (int t = 0; t < L; t++) {
        res += abs(rect[q].c - t) * 1LL * get(rect[q].x1, rect[q].y1, rect[q].x2, rect[q].y2, t);
    }
    
    return res;
}

void run() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
             char c;
             cin >> c;
             a[i][j] = c - 'a';
        }
    }
    
    for (int i = 0; i < k; i++) {
        cin >> rect[i].x1 >> rect[i].y1 >> rect[i].x2 >> rect[i].y2;
        char e;
        cin >> e;
        int c = e - 'a';
        rect[i].c = c;
        cnt[rect[i].x1][rect[i].y1][c]++;
        cnt[rect[i].x1][rect[i].y2 + 1][c]--;
        cnt[rect[i].x2 + 1][rect[i].y1][c]--;
        cnt[rect[i].x2 + 1][rect[i].y2 + 1][c]++;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int t = 0; t < L; t++) {
                cnt[i][j][t] += cnt[i - 1][j][t];
                cnt[i][j][t] += cnt[i][j - 1][t];
                cnt[i][j][t] -= cnt[i - 1][j - 1][t];
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            just[i][j] += just[i - 1][j];
            just[i][j] += just[i][j - 1];
            just[i][j] -= just[i - 1][j - 1];
            
            for (int t = 0; t < L; t++) {
                just[i][j] += abs(t - a[i][j]) * 1LL * cnt[i][j][t];
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cur = 0;
            for (int t = 0; t < L; t++) {
                cur += cnt[i][j][t];
            }
            cnt[i][j][a[i][j]] += k - cur;
            
            for (int t = 0; t < L; t++) {
                cnt[i][j][t] += cnt[i - 1][j][t];
                cnt[i][j][t] += cnt[i][j - 1][t];
                cnt[i][j][t] -= cnt[i - 1][j - 1][t];
            }
        }
    }
    
    ll ans = INF;
    for (int q = 0; q < k; q++) {
        ans = min(ans, calc(q));
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}