#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e6 + 3;

inline void add(int &x, int y) {
    x += y;
    if(x >= MOD)
        x -= MOD;
}

inline int ask(int x) {
    cout << "? " << x << "\n";
    int ans;
    cin >> ans;
    //ans = (1LL * x * x + 1) % MOD;
    return ans;
}

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);

    vector <int> P(11);
    for(i = 0; i <= 10; i++) {
        P[i] = ask(i);

        if(P[i] == 0) {
            cout << "! " << i << "\n";
            return 0;
        }
    }

    vector <int> inv(MOD + 1);
    for(i = 1; i < MOD; i++) {
        inv[i] = lgput(i, MOD - 2);
    }


    vector <int> coef(11);
    for(i = 0; i <= 10; i++) {
        coef[i] = P[i];
        for(int j = 0; j <= 10; j++) {
            if(i != j) {
                coef[i] = (coef[i] * 1LL * (11 - j) * inv[(i - j + MOD) % MOD]) % MOD;
            }
        }
    }


    for(int x = 11; x < MOD; x++) {

        int ans = 0;
        for(i = 0; i <= 10; i++) {
            add(ans, coef[i]);
        }

        if(ans == 0) {
            cout << "! " << x << "\n";
            return 0;
        }

        for(i = 0; i <= 10; i++) {
            if(i == 0) {
                coef[i] = (1LL * coef[i] * (x - i) * inv[(x - 10 + MOD) % MOD]) % MOD;
            }
            else if(i == 10) {
                coef[i] = (1LL * coef[i] * inv[(x - 9 + MOD) % MOD] * (x + 1)) % MOD;
            }
            else {
                coef[i] = (1LL * coef[i] * inv[(x - 10 + MOD) % MOD] * (x + 1)) % MOD;
                coef[i] = (1LL * coef[i] * (x - i + MOD) * inv[(x - i + 1 + MOD) % MOD]) % MOD;
            }

        }
    }

    cout << "! " << -1 << "\n";

    //cin.close();
    //cout.close();
    return 0;
}