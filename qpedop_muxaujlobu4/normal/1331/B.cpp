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
const long long INF = 100000000000000;
const int Y = 100000;
long long arr[Y + 1];
int ans[Y + 1];
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
const long long m = 1000000009;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    cout.precision(15);
    int a;
    cin >> a;
    for (int i = 2; i <= a; ++i) {
        if (a % i == 0) {
            int ans = i;
            int tmp1 = a / i, tmp2 = a / i;
            vector<int>tt;
            while (tmp1) {
                tt.push_back(tmp1 % 10);
                tmp1 /= 10;
            }
            cout << i;
            reverse(tt.begin(), tt.end());
            for (auto x : tt)cout << x;
            return 0;
        }
    }
    return 0;
}