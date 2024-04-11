#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 255;
const int B = 666013;

char mat[MAXN + 1][MAXN + 1];

ull hsh[MAXN + 1][MAXN + 1], pw[26];
int conf[MAXN + 1][MAXN + 1];
ull aux[2 * MAXN + 1], arr[MAXN + 1];
int len[2 * MAXN + 1];

inline ll manacher(int n) {
    int i, sz = 0;
    for(i = 0; i < n; i++) {
        aux[sz++] = 0;
        aux[sz++] = arr[i];
    }
    aux[sz++] = 0;
    ll ans = 0;
    int p = 0;
    for(i = 1; i < sz - 1; i++) {
        if(p + len[p] >= i) {
            len[i] = min(len[2 * p - i], p + len[p] - i);
        }
        while(i - len[i] >= 0 && i + len[i] < sz && aux[i - len[i]] == aux[i + len[i]]) {
            len[i]++;
        }
        ans += len[i] / 2;
        if(p + len[p] < i + len[i]) {
            p = i;
        }
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    pw[0] = 1;
    for(i = 1; i < 26; i++) {
        pw[i] = pw[i - 1] * B;
    }
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> mat[i] + 1;
        vector <int> fr(26);
        for(j = 1; j <= m; j++) {
            mat[i][j] -= 'a';
            fr[mat[i][j]]++;
            hsh[i][j] = hsh[i][j - 1] + pw[mat[i][j]];
            conf[i][j] = (conf[i][j - 1] ^ (1 << mat[i][j]));
        }
    }
    ll ans = 0;
    for(int c1 = 0; c1 < m; c1++) {
        for(int c2 = c1 + 1; c2 <= m; c2++) {
            i = 1;
            while(i <= n) {
                j = i;
                int sz = 0;
                while(j <= n && __builtin_popcount(conf[j][c2] ^ conf[j][c1]) <= 1) {
                    arr[sz++] = hsh[j][c2] - hsh[j][c1];
                    j++;
                }
                if(j > i) {
                    ans += manacher(sz);
                }
                i = j + 1;
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}