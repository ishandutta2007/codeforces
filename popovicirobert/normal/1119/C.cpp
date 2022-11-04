#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

/*
const int MOD = ;

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
*/

using namespace std;

const int MAXN = 500;

int a[MAXN + 1][MAXN + 1], b[MAXN + 1][MAXN + 1];

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif // ONPC
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }

    for(i = 1; i < n; i++) {
        for(j = 1; j < m; j++) {
            if(a[i][j] != b[i][j]) {
                a[i][j] ^= 1;
                a[i + 1][j] ^= 1;
                a[i][j + 1] ^= 1;
                a[i + 1][j + 1] ^= 1;
            }
        }
    }

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(a[i][j] != b[i][j]) {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";

    //cin.close();
    //cout.close();
    return 0;
}