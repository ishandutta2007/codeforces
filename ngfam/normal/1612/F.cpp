#include <bits/stdc++.h>
#define long long long

using namespace std;

const int maxn = 200005;
const int LG = 65;

int n, m, q;
int f[LG][maxn];
int f2[LG][maxn];

int rev[maxn];

vector<int> vec[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> q;

    while(q--) {
        int x, y; cin >> x >> y;
        vec[x].push_back(y);
    }

    for(int i = 0; i <= n; ++i) {
        sort(vec[i].begin(), vec[i].end());
    }

    for(int i = 0; i < LG; ++i) for(int j = 0; j < maxn; ++j) f[i][j] = -maxn-maxn-maxn;

    auto find = [&](int x, int y) {
        return binary_search(vec[x].begin(), vec[x].end(), y);
    };

    f[0][1] = 1;
    if (find(1, 1)) f2[0][1] = 1;

    auto maximize = [&](int mv, int i, int val) {
        if (find(i, val)) f2[mv][i] = max(f2[mv][i], val);
        f[mv][i] = max(f[mv][i], val);
    };

    for(int mv = 0; mv + 1 < LG; ++mv) {
        for(int i = 1; i <= n; ++i) {
            if (f[mv][i] < 0) continue;
            // use f
            // 1. new armor
            {
                int newArmor = min(n, i + f[mv][i]);
                maximize(mv+1, newArmor, f[mv][i]);
                maximize(mv+1, newArmor-1, f[mv][i]);
            }
            // 2. new weapon
            {
                int newWeapon = min(m, i + f[mv][i]);
                maximize(mv+1, i, newWeapon);
                maximize(mv+1, i, newWeapon - 1);
            }
            // use f2
            // 1. new armor
            {
                int newArmor = min(n, i + f2[mv][i] + 1);
                maximize(mv+1, newArmor, f[mv][i]);
                maximize(mv+1, newArmor-1, f[mv][i]);
            }
            // 2. new weapon
            {
                int newWeapon = min(m, i + f2[mv][i] + 1);
                maximize(mv+1, i, newWeapon);
                maximize(mv+1, i, newWeapon - 1);
            }
        }
    }

    memset(rev, 60, sizeof(rev));
    rev[n] = 0;
    for(int i = n - 1; i >= 0; --i) {
        int nxt = min(n, i + m + find(i, m));
        rev[i] = rev[nxt] + 1;
    }

    int ans = maxn + maxn;
    for(int i = 0; i < LG; ++i) {
        if (f[i][n] >= 0) {
            int step = i, w = f[i][n];
            while (w < m) {
                step++;
                w = w + n + find(n, w);
            }
            ans = min(ans, step);
        }
        for(int j = 1; j <= n; ++j) {
            if (f[i][j] == m) {
                ans = min(ans, i + rev[j]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}