#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long 

using namespace std;

int root = 5;

int powmod(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int solve(int a, int b, int m) {
    int n = (int) sqrt (m + .0) + 1;
    map<int, int> vals;
    for (int p = n; p >= 1; --p)
        vals[powmod(a, p * n, m)] = p;
    for (int q = 0; q <= n; ++q) {
        int cur = (powmod(a, q, m) * b) % m;
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}

std::vector<std::vector<int> > matrix_mult(std::vector<std::vector<int> >& a, std::vector<std::vector<int> >& b, int mod)
{
    std::vector<std::vector<int> > gr(a.size(), std::vector<int> (a.size(), 0));
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < a.size(); ++j)
            for (int k = 0; k < a.size(); ++k)
                gr[i][j] = (gr[i][j] + a[i][k] * b[k][j]) % mod;
    return gr;
}

std::vector<std::vector<int> > matrix_expo(std::vector<std::vector<int> >& a, int n, int mod)
{
    std::vector<std::vector<int> > res(a.size(), std::vector<int> (a.size(), 0));
    for (int i = 0; i < a.size(); ++i)
        res[i][i] = 1;
    while (n) {
        if (n & 1ll)
            res = matrix_mult(res, a, mod);
        a = matrix_mult(a, a, mod);
        n >>= 1;
    }
    return res;
}


int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int mod = 1e9 + 7;
    int n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    n -= 3;
    f1 = solve(root, f1, mod);
    f2 = solve(root, f2, mod);
    f3 = solve(root, f3, mod);
    c = solve(root, c, mod);
    std::vector<std::vector<int> > mat(5, std::vector<int> (5, 0));

    mat[0][0] = 1;
    mat[1][0] = 1;
    mat[2][0] = 1;
    mat[3][0] = 1;

    mat[0][1] = 1;

    mat[1][2] = 1;

    mat[3][3] = 1;
    mat[4][3] = 1;

    mat[4][4] = 1;
    mat = matrix_expo(mat, n, mod - 1);
    std::vector<int> v = {f3, f2, f1, 2 * c, 2 * c};
    int ans = 0;
    for (int i = 0; i < 5; ++i)
        ans = (ans + (mat[i][0] * v[i]) % (mod - 1)) % (mod - 1);
    cout << powmod(root, ans, mod);
}