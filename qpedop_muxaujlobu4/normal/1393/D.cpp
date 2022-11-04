#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<random>
#define double long double
//#define int short
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 2e17;
const long long m = 1000000007;
const int Y = 200101;
int arr[Y];
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>>f(n, vector<char>(m));
        vector<vector<int>>b(n, vector<int>(m, 1));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> f[i][j];
                if (j != 0 && j + 1 < m && i - 2 >= 0 && f[i][j] == f[i - 2][j] && f[i][j] == f[i - 1][j - 1] && f[i][j] == f[i - 1][j] && f[i][j] == f[i - 1][j + 1]) {
                    b[i][j] = min(min(b[i - 2][j], b[i - 1][j - 1]), b[i - 1][j + 1]) + 2;
                }
                ans += (b[i][j] + 1) / 2;
            }
        }
        cout << ans;
    }
    return 0;
}