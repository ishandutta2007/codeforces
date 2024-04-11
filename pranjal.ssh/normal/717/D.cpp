#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define rep(i, n) for(int i = 0; i < (n); ++i)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define mset(a, v) memset(a, v, sizeof(a))
#define sz(a) ((int)a.size())

#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << (x) << " "
#define dbs(x) cerr << (x) << " "

const int X = 130;
const int DIM = 128;

double dp[X][X];
bool vis[X][X];
double prob[X];
int n, x;

typedef long double ld;

struct matrix {
    ld val[DIM][DIM];

    matrix() {
        mset(val, 0);
    }
};

matrix mul(matrix a, matrix b) {
    matrix c;
    rep (i, DIM) {
        rep (j, DIM) {
            rep (k, DIM) {
                c.val[i][j] += a.val[i][k] * b.val[k][j];
            }
        }
    }
    return c;
}

matrix power(matrix a, int n) {
    matrix ret;
    rep (i, DIM) {
        ret.val[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) {
            ret = mul(ret, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return ret;
}

// double go(int rem, int xorVal) {
//     if (rem == 0) {
//         return xorVal > 0;
//     }
//     double& ret = dp[rem][xorVal];
//     if (vis[rem][xorVal]) {
//         return ret;
//     }
//     vis[rem][xorVal] = true;
//     ret = 0;
//     rep(i, x + 1) {
//         ret += prob[i] * go(rem - 1, xorVal ^ i);
//     }
//     return ret;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        
    cin >> n >> x;

    double p2 = 0;
    rep (i, x + 1) {
        cin >> prob[i];
        // dbg(i), dbg(prob[i]), dbn;
        p2 += prob[i] * prob[i];
    }
    matrix mat;
    rep (i, DIM) {
        rep (j, x + 1) {
            mat.val[i][i ^ j] += prob[j];
        }
    }

    mat = power(mat, n);

    ld ans = 0;
    for (int i = 1; i < DIM; ++i) {
        ans += mat.val[0][i];
    }
    cout << setprecision(10) << fixed << ans << "\n";
    return 0;
}