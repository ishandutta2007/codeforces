#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = 998244353;

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

const int MAXN = 3000;

int mat[MAXN + 1][MAXN + 1], aux[MAXN + 1][MAXN + 1];
deque <int> deq;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m, a, b;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> a >> b;

    int g0, x, y, z;
    cin >> g0 >> x >> y >> z;

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            mat[i][j] = g0;
            g0 = (1LL * g0 * x + y) % z;
        }
    }

    for(i = 1; i <= n; i++) {
        deq.clear();
        for(j = 1; j <= m; j++) {
            if(deq.size() && deq.front() <= j - b) {
                deq.pop_front();
            }
            while(deq.size() && mat[i][deq.back()] >= mat[i][j]) {
                deq.pop_back();
            }
            deq.push_back(j);
            if(j >= b) {
                aux[i][j - b + 1] = mat[i][deq.front()];
            }
        }
    }

    ll ans = 0;
    for(j = 1; j <= m - b + 1; j++) {
        deq.clear();
        for(i = 1; i <= n; i++) {
            if(deq.size() && deq.front() <= i - a) {
                deq.pop_front();
            }
            while(deq.size() && aux[deq.back()][j] >= aux[i][j]) {
                deq.pop_back();
            }
            deq.push_back(i);
            if(i >= a) {
                ans += aux[deq.front()][j];
            }
        }
    }

    cout << ans;

    return 0;
}