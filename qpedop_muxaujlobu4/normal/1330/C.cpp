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
const int Y = 100000;
const long long m = 1000000009;
pair<long long, long long> arr[Y + 1];
int ans[Y + 1];
long long css[Y + 10];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    int n, m;
    cin >> n >> m;
    if (m > n) {
        cout << -1;
        return 0;
    }
    long long ss = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
        ss += arr[i].first;
    }
    if (ss < n) {
        cout << -1;
        return 0;
    }
    css[m + 1] = 0;
    for (int i = m; i > 0; --i) {
        css[i] = css[i + 1] + arr[i].first;
    }
    long long j = 1;
    for (int i = 1; i <= m; ++i, ++j) {
        int nb, l;
        tie(l, nb) = arr[i];
        j = max((long long)j, n - css[i] + 1);
        ans[nb] = j;
        if (j + l - 1 > n) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 1; i <= m; ++i)cout << ans[i] << " ";
    return 0;
}
/* Wed Apr 01 2020 21:05:33 GMT+0300 (MSK) */