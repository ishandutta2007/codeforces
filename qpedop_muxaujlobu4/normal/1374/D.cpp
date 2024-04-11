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
using namespace std;
int gcd(int i, int j) {
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
const long long INF = 1e17;
const long long m = 1000000007;
const int Y = 200100;
long long ar[Y];
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        long long n, k, ans = 0;
        cin >> n >> k;
        vector<long long>a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] %= k;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n;) {
            int j = i;
            for (; j < n; ++j) {
                if (a[i] != a[j])break;
            }
            long long len = j - i;
            if (a[i] == 0) {
                i = j;
                continue;
            }
            long long tmp = k - a[i] + 1 + (len - 1) * k;
            ans = max(ans, tmp);
            i = j;
        }
        cout << ans << endl;
    }
    return 0;
}
//freopen("painter.in", "r", stdin);
//freopen("painter.out", "w", stdout);
/*
3
ooo
o..
o..
*/
/* Fri May 15 2020 19:54:42 GMT+0300 (MSK) */

/* Wed May 20 2020 19:33:48 GMT+0300 (MSK) */