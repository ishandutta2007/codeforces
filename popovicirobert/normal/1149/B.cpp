#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

/*
const int MOD = ;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}
*/

using namespace std;

const int MAXN = (int) 1e5 + 5;

char str[MAXN + 1];
int nxt[MAXN + 1][26];

int dp[251][251][251];
char cur[4][500];
int sz[4], n;

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, j, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q >> str + 1;

    for(j = 0; j < 26; j++) {
        nxt[n + 1][j] = n + 1;
    }

    for(i = n; i >= 1; i--) {
        str[i] -= 'a';
        for(j = 0; j < 26; j++) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][str[i]] = i;
    }

    while(q--) {
        char sign;
        int id;
        cin >> sign >> id;

        if(sign == '-') {
            sz[id]--;
        }
        else {
            char ch;
            cin >> ch;
            cur[id][++sz[id]] = ch - 'a';

            int la = 0, ra = sz[1], lb = 0, rb = sz[2], lc = 0, rc = sz[3];

            if(id == 1) {
                la = sz[1] - 1, ra = sz[1];
            }
            if(id == 2) {
                lb = sz[2] - 1, rb = sz[2];
            }
            if(id == 3) {
                lc = sz[3] - 1, rc = sz[3];
            }

            for(int a = la + (id == 1); a <= ra; a++) {
                for(int b = lb + (id == 2); b <= rb; b++) {
                    for(int c = lc + (id == 3); c <= rc; c++) {
                        dp[a][b][c] = MAXN + 1;
                    }
                }
            }

            dp[0][0][0] = 0;

            for(int a = la; a <= ra; a++) {
                for(int b = lb; b <= rb; b++) {
                    for(int c = lc; c <= rc; c++) {
                        if(dp[a][b][c] >= n) {
                            continue;
                        }

                        if(a < sz[1]) {
                            dp[a + 1][b][c] = min(dp[a + 1][b][c], nxt[dp[a][b][c] + 1][cur[1][a + 1]]);
                        }
                        if(b < sz[2]) {
                            dp[a][b + 1][c] = min(dp[a][b + 1][c], nxt[dp[a][b][c] + 1][cur[2][b + 1]]);
                        }
                        if(c < sz[3]) {
                            dp[a][b][c + 1] = min(dp[a][b][c + 1], nxt[dp[a][b][c] + 1][cur[3][c + 1]]);
                        }
                    }
                }
            }
        }

        if(dp[sz[1]][sz[2]][sz[3]] >= n + 1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }

    }

    //cin.close();
    //cout.close();
    return 0;
}