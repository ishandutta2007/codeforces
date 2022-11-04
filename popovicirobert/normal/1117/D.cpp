#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;

inline void mod(int &x) {
    if(x >= MOD)
         x -= MOD;
}

class Matrix {

private:
    inline void mod(int &x) {
        if(x >= MOD)
            x -= MOD;
    }
    int MOD;

public:

    int **mat;
    int n, m;

    inline void init(int _n, int _m, int _MOD) {
        n = _n, m = _m;
        MOD = _MOD;
        mat = new int*[n + 1];
        for(int i = 1; i <= n; i++) {
            mat[i] = new int[m + 1];
            for(int j = 1; j <= m; j++) {
                mat[i][j] = 0;
            }
        }
    }

    inline void I() {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                mat[i][j] = (i == j);
            }
        }
    }

    inline void O() {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                mat[i][j] = 0;
            }
        }
    }

    Matrix operator +(const Matrix &other) {
        Matrix res;
        res.init(n, m, MOD);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                res.mat[i][j] = mat[i][j] + other.mat[i][j];
                mod(res.mat[i][j]);
            }
        }
        return res;
    }

    Matrix operator -(const Matrix &other) {
        Matrix res;
        res.init(n, m, MOD);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                res.mat[i][j] = mat[i][j] - other.mat[i][j] + MOD;
                mod(res.mat[i][j]);
            }
        }
        return res;
    }

    Matrix operator *(const Matrix &other) {
        Matrix res;
        res.init(n, other.m, MOD);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= other.m; j++) {
                for(int k = 1; k <= m; k++) {
                    res.mat[i][j] = (res.mat[i][j] + 1LL * mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix operator *(const int val) {
        Matrix res;
        res.init(n, m, MOD);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                res.mat[i][j] = (1LL * mat[i][j] * val) % MOD;
            }
        }
        return res;
    }

    void operator +=(const Matrix &other) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                mat[i][j] += other.mat[i][j];
                mod(mat[i][j]);
            }
        }
    }

    void operator -=(const Matrix &other) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                mat[i][j] += MOD - other.mat[i][j];
                mod(mat[i][j]);
            }
        }
    }

    void operator *=(const Matrix &other) {
        int res[n + 1][other.m + 1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= other.m; j++) {
                res[i][j] = 0;
                for(int k = 1; k <= m; k++) {
                    res[i][j] = (res[i][j] + 1LL * mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= other.m; j++) {
                mat[i][j] = res[i][j];
            }
        }
    }

    void operator *=(const int val) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                mat[i][j] = (1LL * mat[i][j] * val) % MOD;
            }
        }
    }

    void operator =(const Matrix &other) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                mat[i][j] = other.mat[i][j];
            }
        }
    }

};

const int MAXM = 100;

int dp[MAXM + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, m;
    ll n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    if(n < m) {
        cout << 1;
        return 0;
    }
    Matrix sol, a;
    sol.init(m, m, MOD);
    a.init(m, m, MOD);
    sol.I();
    for(i = 1; i < m; i++) {
        a.mat[i + 1][i] = 1;
    }
    a.mat[1][m] = a.mat[m][m] = 1;
    while(n > 0) {
        if(n & 1)
            sol *= a;
        n >>= 1;
        a = a * a;
    }
    int ans = sol.mat[m][m];
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}