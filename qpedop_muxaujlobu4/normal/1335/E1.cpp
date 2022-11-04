#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<ctime>
#include<bitset>
#include<random>
using namespace std;
//#define double long long;
typedef unsigned long long ull;
#define double long double
const double e = 0.00000005;
const double pi = 3.1415926535898;
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
//const long long INF = 100000000000000;
const int Y = 200100;
const int INF = 100000000;
const long long m = 998244353;
int arr[Y];
int Mat[9][9];
int PS[201][Y];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int res = 1;
        vector<pair<int, int>>spp;
        for (int j = 1; j <= 26; ++j)PS[j][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 26; ++j)PS[j][i] = PS[j][i - 1];
            cin >> arr[i];
            ++PS[arr[i]][i];
        }
        for (int j = 1; j <= 26; ++j)res = max(res, PS[j][n]);
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (arr[i] != arr[j])continue;
                for (int kk = 1; kk <= 26; ++kk) {
                    for (int k = 1; k <= 26; ++k) {
                        int mm = min(PS[k][i], PS[k][n] - PS[k][j - 1]);
                        int tmp;
                        if (i + 1 == j)tmp = 0;
                        else tmp = PS[kk][j - 1] - PS[kk][i];
                        res = max(res, 2 * mm + tmp);
                    }
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
/*
782574093100800
1
782574093100800 1
*/