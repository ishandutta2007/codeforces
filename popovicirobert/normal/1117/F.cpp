#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5 + 5;

char str[MAXN + 1];
bool ok[17][17];

vector <int> pos[17];
int prv[MAXN + 1][17];
int cnt[MAXN + 1][17];

bitset < (1 << 17) > dp, aux;
int p;

inline void solve(int a, int b, int conf) {
    if(aux[conf] == 0) {
        return ;
    }
    aux[conf] = 0;
    for(int i = 0; i < p; i++) {
        if((conf & (1 << i)) == 0 && i != a && i != b) {
            solve(a, b, conf ^ (1 << i));
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> p;
    cin >> str + 1;
    for(i = 1; i <= n; i++) {
        str[i] -= 'a';
        pos[str[i]].push_back(i);
    }
    for(i = 1; i <= n; i++) {
        for(j = 0; j < p; j++) {
            prv[i][j] = prv[i - 1][j];
            cnt[i][j] = cnt[i - 1][j];
        }
        prv[i][str[i]] = i;
        cnt[i][str[i]]++;
    }
    for(i = 0; i < p; i++) {
        for(j = 0; j < p; j++) {
            cin >> ok[i][j];
        }
    }
    dp.set();
    for(int a = 0; a < p; a++) {
        for(int b = 0; b < p; b++) {
            if(ok[a][b]) {
                continue;
            }
            aux.set();
            for(auto it : pos[a]) {
                if(prv[it - 1][b] == 0) {
                    continue;
                }
                int conf = 0;
                for(int c = 0; c < p; c++) {
                    if(prv[it - 1][c] > prv[it - 1][b] && c != a && c != b) {
                        conf |= (1 << c);
                    }
                }
                solve(a, b, conf);
            }
            dp &= aux;
        }
    }
    dp[0] = 1;
    for(int conf = 1; conf < (1 << p); conf++) {
        int cur = dp[conf];
        dp[conf] = 0;
        for(i = 0; i < p; i++) {
            if((conf & (1 << i)) && dp[conf ^ (1 << i)]) {
                dp[conf] = cur;
            }
        }
    }
    int ans = n;
    for(int conf = 0; conf < (1 << p); conf++) {
        int cur = 0;
        for(i = 0; i < p; i++) {
            if(conf & (1 << i)) {
                cur += cnt[n][i];
            }
        }
        if(dp[conf]) {
            ans = min(ans, n - cur);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}