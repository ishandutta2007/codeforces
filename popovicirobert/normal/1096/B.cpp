#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MOD = 998244353;
const int MAXN = (int) 2e5 + 5;

char str[MAXN + 1];
int pref[MAXN + 1][26], suff[MAXN + 1][26];
int fr[26];

inline bool ok(int a, int b) {
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        if(pref[a][i] + suff[b][i]) {
            ans++;
        }
    }
    return ans <= 1;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> str + 1;
    for(i = 1; i <= n; i++) {
        str[i] -= 'a';
        fr[str[i]]++;
        for(j = 0; j < 26; j++) {
            pref[i][j] = pref[i - 1][j];
        }
        pref[i][str[i]]++;
    }
    for(i = n; i >= 1; i--) {
        for(j = 0; j < 26; j++) {
            suff[i][j] = suff[i + 1][j];
        }
        suff[i][str[i]]++;
    }
    int ans = 0;
    int pos = 1;
    for(i = 0; i <= n; i++) {
        pos = max(pos, i + 1);
        while(pos <= n && !ok(i, pos)) {
            pos++;
        }
        //cerr << i << " " << pos << "\n";
        if(ok(i, pos)) {
            ans += n - pos + 2;
            ans %= MOD;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}