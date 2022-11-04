#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = ;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}


inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/


using namespace std;

const int MAXN = (int) 2e5;

char str[MAXN + 1];
int fr[26][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, i, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> str + 1;
    for(i = 1; i <= n; i++) {
        str[i] -= 'a';
        for(j = 0; j < 26; j++) {
            fr[j][i] = fr[j][i - 1];
        }
        fr[str[i]][i]++;
    }

    cin >> m;
    while(m--) {
        string cur;
        cin >> cur;

        vector <int> cnt(26);
        for(auto it : cur) {
            cnt[it - 'a']++;
        }

        int ans = 0;
        for(i = 0; i < 26; i++) {
            ans = max(ans, upper_bound(fr[i], fr[i] + n + 1, cnt[i] - 1) - fr[i]);
        }

        cout << ans << "\n";
    }

    //cin.close();
    //cout.close();
    return 0;
}