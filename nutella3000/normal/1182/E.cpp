#include <bits/stdc++.h>

using namespace std;
#define int long long
#define loop1(from, n) for(int i = from; i < n;i++)
#define loop2(from, n) for(int i = from;i >= n;i--)
const int inf = 1e9 + 6;
struct matrix{
    int a[5][5];
    matrix(vector<vector<int>> b) {
        for(int i = 0;i < 5;i++) {
            for(int j = 0;j < 5;j++) a[i][j] = b[i][j];
        }
    }
    matrix() {};
};
matrix mul(matrix A, matrix B) {
    matrix C;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            C.a[i][j] = 0;
            for (int v = 0; v < 5; v++)
                C.a[i][j] += (A.a[v][j] * B.a[i][v]) % inf;
            C.a[i][j] %= inf;
        }
    return C;
}
matrix power(matrix A, int k) {
    if (k == 1)
        return A;
    matrix B = power(A, k / 2);
    B = mul(B, B);
    if (k % 2 != 0)
        B = mul(A, B);
    return B;
}
int mod = 1e9 + 7;
int binpow (int a, int n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return (binpow (a, n-1) * a) % mod;
    else {
        int b = binpow (a, n/2);
        return (b * b) % mod;
    }
}
int32_t main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    vector<vector<int>> qq;
    for(int i = 0;i < 5;i++) {
        qq.emplace_back(vector<int>());
        for(int j = 0;j < 5;j++) qq[i].emplace_back(0);
    }

    for(int i = 0;i < 3;i++) qq[0][i] = 1;
    qq[1][0] = 1;
    qq[2][1] = 1;
    matrix g = matrix(qq);

    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 5;j++) qq[i][j] = 0;
    }

    qq[1][0] = 1;
    qq[2][0] = -6;
    qq[2][1] = 2;
    qq[2][2] = 1;
    qq[2][3] = 1;
    qq[2][4] = 1;
    qq[2][5] = 1;
    qq[3][2] = 1;
    qq[4][3] = 1;
    qq[1][1] = 1;
    qq[0][0] = 1;

    matrix p = matrix(qq);
    matrix one = power(g, n - 3);
    matrix two = power(p, n - 3);

    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 5;j++) qq[i][j] = 0;
    }

    for(int i = 0;i < 3;i++) qq[i][i] = 1;
    matrix rr = matrix(qq);
    one = mul(rr, one);


    for(int i = 0;i < 3;i++) qq[i][i] = 0;
    qq[0][0] = 1;
    qq[1][0] = 4;
    rr = matrix(qq);
    two = mul(rr, two);
    int ans = (binpow(f3, one.a[0][0]) * binpow(f2, one.a[0][1])) % mod;
    ans = (ans * binpow(f1, one.a[0][2])) % mod;
    ans = (ans * binpow(c, two.a[2][0])) % mod;
    cout << ans;
}