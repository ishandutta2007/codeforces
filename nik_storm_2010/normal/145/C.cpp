#include <cstdio>
#include <map>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
const int M = 2000;
const int MOD = 1e9 + 7;

map <int, int> base;
vector <int> all;
int f[M][M];
long long fact[N];

bool check(int x) {
    while (x > 0) {
        int c = x % 10;
        if (c != 4 && c != 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int power(int x, int k) {
    if (k == 0) {
        return 1;
    }
    int c = power(x, k / 2);
    c = (1LL * c * c) % MOD;
    if (k % 2) {
        c = 1LL * c * x % MOD;
    }
    return c;
}

int c(int n, int k) {
    return (fact[n] * power(fact[n - k] * fact[k] % MOD, MOD - 2) % MOD);
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    int n, k;
    scanf("%d %d", &n, &k);
    int usual = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (!check(x)) {
            usual++;
        } else {
            base[x]++;
        }
    }
    int unusual = (int)base.size();
    for (map <int, int>::iterator it = base.begin(); it != base.end(); it++) {
        all.push_back(it->second);
    }
    f[0][0] = 1;
    int cnt = (int)all.size();
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j <= i; j++) {
            f[i + 1][j] = (f[i + 1][j] + f[i][j]) % MOD;
            f[i + 1][j + 1] = (f[i + 1][j + 1] + 1LL * f[i][j] * all[i]) % MOD;
        }
    }
    long long ans = 0;
    for (int cnt_usual = 0; cnt_usual <= k; cnt_usual++) {
        if (cnt_usual > usual) {
            break;
        }
        int cnt_unusual = k - cnt_usual;
        if (cnt_unusual > unusual) {
            continue;
        }
        ans = (ans + 1LL * c(usual, cnt_usual) * f[unusual][cnt_unusual]) % MOD;
    }
    printf("%I64d\n", ans);
    return 0;
}