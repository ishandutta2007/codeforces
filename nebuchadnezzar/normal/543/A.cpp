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
const int MAXN = 505;

int n, m, b;
int inp[MAXN];
LL mod;

LL d[2][MAXN][MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m >> b >> mod;

    for (int i = 0; i < n; ++i) {        
        cin >> inp[i];        
    }

    d[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int i2 = i & 1;
        //cerr << i2 << endl;
        //cerr << inp[i - 1] << endl;
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= b; ++k) {
                d[i2][j][k] = d[1 - i2][j][k];
                if (k >= inp[i - 1] && j > 0) {
                    //if (d[i2][j - 1][k - inp[i]])
                    //cerr << j << " " << k << " " << d[i2][j - 1][k - inp[i]] << endl;
                    d[i2][j][k] += d[i2][j - 1][k - inp[i - 1]];
                }
                d[i2][j][k] %= mod;
                //cerr << d[i2][j][k] << " ";
            }
            //cerr << endl;
        }
        //cerr << endl;
        //cerr << d[i2][5][6] << endl;
    }

    LL sum = 0;

    for (int i = 0; i <= b; ++i) {
        sum = (sum + d[n & 1][m][i]) % mod;
    }
    cout << sum << endl;

    return 0;
}