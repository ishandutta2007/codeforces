#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int SZM = 4;

LL n, k, l, mod;

struct matrix {
    LL m[SZM][SZM];
    matrix operator* (matrix matr) {
        matrix ret;
        for (int i = 0; i < SZM; ++i) {
            for (int j = 0; j < SZM; ++j) {
                LL now = 0;
                for (int k = 0; k < SZM; ++k) {
                    now = (now + m[i][k] * matr.m[k][j]) % mod;
                }
                ret.m[i][j] = now;
            }
        }
        return ret;
    }   
};

matrix one;

matrix pow(matrix a, LL b) {
    if (b == 0) {
        return one;
    }
    if (b == 1) {
        return a;
    }   
    matrix ret = pow(a, b / 2);
    ret = ret * ret;
    if (b % 2) {
        ret = ret * one;
    }
    return ret;
}

LL mpow(LL a, LL b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    LL ret = mpow(a, b / 2);
    ret = (ret * ret) % mod;
    if (b & 1) {
        ret = (ret * a) % mod;
    }
    return ret;
}


int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> k >> l >> mod;

    for (int i = 0; i < 4; ++i) {
        one.m[0][i] = 1;
        one.m[2][i] = 1;
    }
    one.m[1][0] = one.m[1][1] = 1;
    one.m[1][2] = one.m[1][3] = -1;
    one.m[3][2] = 1;


    /*
    mod = 1e18 + 7;    
    for (int i = 0; i <= 30; ++i) {
        cout << pow(one, i).m[0][0] << endl;
    }
    return 0;*/

    matrix ans = pow(one, n - 1);
    LL prod2 = ans.m[0][0];
    ans = ans * one * one;
    LL prod = ans.m[0][2];
    //cerr << prod << endl;

    LL tmp = k;
    int c = 0;
    int num = 0;
    while (tmp) {
        if (c >= l) {
            cout << 0 << endl;
            return 0;
        }
        num += tmp & 1;
        tmp >>= 1;
        ++c;
    }

    //cerr << num << endl;

    LL a = mpow(prod, l - num);

    //cerr << a << endl;

    

    //cerr << prod2 << endl;

    //cerr << prod2 << " " << num << endl;

    a = (a * mpow(prod2, num)) % mod;

    cout << a << endl;

    return 0;
}