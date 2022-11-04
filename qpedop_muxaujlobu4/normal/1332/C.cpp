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
const int Y = 1000;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
int arr[200000][26];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    cout.precision(15);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ch = n / k;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < 26; ++j)arr[i][j] = 0;
        }
        for (int i = 0; i < n; ++i) {
            int w = s[i] - 'a';
            ++arr[i % k][w];
        }
        if (k == 1) {
            int mx = 0;
            for (int i = 0; i < 26; ++i)mx = max(arr[0][i], mx);
            cout << n - mx << "\n";
            continue;
        }
        int ans = 0;
        for (int i = 0; 2 * i + 1 < k; ++i) {
            int mx = 0;
            for (int j = 0; j < 26; ++j) {
                arr[i][j] += arr[k - 1 - i][j];
                mx = max(arr[i][j], mx);
            }
            ans += ch * 2 - mx;
        }
        if (k % 2 == 1) {
            int mx = 0;
            for (int j = 0; j < 26; ++j) {
                mx = max(arr[k/2][j], mx);
            }
            ans += ch  - mx;
        }
        cout << ans << "\n";
    }
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */

/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */

/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */