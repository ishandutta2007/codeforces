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
int pr[201][Y];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    int t = getint();
    while (t--) {
        int n = getint();
        vector<vector<int>>sp(201);
        for (int i = 1; i <= n; ++i) {
            arr[i] = getint();
            for (int j = 1; j <= 200; ++j)pr[j][i] = pr[j][i - 1];
            ++pr[arr[i]][i];
            sp[arr[i]].push_back(i);
        }
        int res = 0;
        for (int i = 1; i <= 200; ++i) {
            int kl = pr[i][n];
            res = max(res, kl);
            for (int hh = 1; 2 * hh <= kl; ++hh) {
                int ff = sp[i][hh - 1];
                int ll = sp[i][kl - hh];
                int mxx = 0;
                for (int jj = 1; jj <= 200; ++jj)mxx = max(mxx, pr[jj][ll - 1] - pr[jj][ff]);
                res = max(res, hh * 2 + mxx);
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