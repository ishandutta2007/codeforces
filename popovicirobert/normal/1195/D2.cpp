#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


const int MOD = 998244353;

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
}

using namespace std;

inline int get(int x) {
    int ans = 0;
    while(x > 0) {
        ans++;
        x /= 10;
    }
    return ans;
}

int fr[20], pw[100];
int sum[20][20];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    pw[0] = 1;
    for(i = 1; i < 100; i++) {
        pw[i] = (1LL * pw[i - 1] * 10) % MOD;
    }

    cin >> n;
    vector <int> arr(n + 1);

    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        int cur = get(arr[i]);
        fr[cur]++;

        int p10 = 1;
        for(j = cur - 1; j >= 0; j--) {
            sum[cur][j] += (arr[i] / p10) % 10;
            p10 *= 10;
        }
    }

    int ans = 0;
    for(i = 1; i <= n; i++) {
        vector <int> aux;
        int nr = arr[i];
        while(nr > 0) {
            aux.push_back(nr % 10);
            nr /= 10;
        }
        reverse(aux.begin(), aux.end());

        int d1 = get(arr[i]);

        for(int d2 = 1; d2 <= 15; d2++) {
            if(fr[d2] == 0) {
                continue;
            }
            if(d1 >= d2) {
                for(j = 0; j < d1 - d2; j++) {
                    ans = (ans + 1LL * fr[d2] * aux[j] * pw[d1 + d2 - j - 1]) % MOD;
                }
                for(j = 0; j < d2; j++) {
                    ans = (ans + 1LL * sum[d2][j] * pw[2 * d2 - 2 * j - 2]) % MOD;
                    ans = (ans + 1LL * aux[d1 - d2 + j] * pw[2 * d2 - 2 * j - 1] * fr[d2]) % MOD;
                }
            }
            else {
                for(j = 0; j < d2 - d1; j++) {
                    ans = (ans + 1LL * sum[d2][j] * pw[d1 + d2 - j - 1]) % MOD;
                }
                for(j = 0; j < d1; j++) {
                    ans = (ans + 1LL * aux[j] * pw[2 * d1 - 2 * j - 1] * fr[d2]) % MOD;
                    ans = (ans + 1LL * sum[d2][j + d2 - d1] * pw[2 * d1 - 2 * j - 2]) % MOD;
                }
            }
        }
    }

    cout << ans;

    return 0;
}