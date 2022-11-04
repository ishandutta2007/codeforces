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
#include<random>
using namespace std;
//#define double long long;
typedef long double ld;
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
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
const long long INF = 100000000000000;
const int Y = 1000000;
const long long m = 1000000009;
int arr[2000];
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
        int n, x;
        cin >> n >> x;
        vector<int>vals(n);
        for (int i = 0; i < n; ++i)cin >> vals[i];
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int res = 1;
        for (int i = 1, j = 0; i <= 300; ++i) {
            if (j<vals.size() && vals[j] == i)++j;
            if (i - j > x) {
                res = i - 1;
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
/* Wed Apr 01 2020 21:05:33 GMT+0300 (MSK) */