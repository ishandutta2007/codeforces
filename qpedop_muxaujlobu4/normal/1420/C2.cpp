#pragma comment(linker, "/STACK:2759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include <unordered_map>
#include<random>
#include<ctime>
#define double long double
//#define int long long
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
const double INF = 1e17;
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 300100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
   // file_inc();
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        long long ans = 0;
        vector<int>a(n + 2);
        vector<int>used(n + 2, 0);
        used[0] = used[n + 1] = 1;
        for (int i = 1; i <= n; ++i)cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                ans += a[i];
                used[i] = 1;
            }
            if (a[i - 1] > a[i] && a[i + 1] > a[i]) {
                used[i] = 1;
                ans -= a[i];
            }
        }
        cout << ans << "\n";
        while (q--) {
            int l, r;
            cin >> l >> r;
            for (int i = r - 1; i <= r + 1; ++i) {
                if (!used[i] || i == 0 || i == n + 1)continue;
                if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                    ans -= a[i];
                    used[i] = 0;
                }
                if (a[i - 1] > a[i] && a[i + 1] > a[i]) {
                    ans += a[i];
                    used[i] = 0;
                }
            }
            for (int i = l - 1; i <= l + 1; ++i) {
                if (!used[i] || i == 0 || i == n + 1)continue;
                if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                    ans -= a[i];
                    used[i] = 0;
                }
                if (a[i - 1] > a[i] && a[i + 1] > a[i]) {
                    ans += a[i];
                    used[i] = 0;
                }
            }
            swap(a[l], a[r]);
            for (int i = r - 1; i <= r + 1; ++i) {
                if (used[i])continue;
                if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                    ans += a[i];
                    used[i] = 1;
                }
                if (a[i - 1] > a[i] && a[i + 1] > a[i]) {
                    used[i] = 1;
                    ans -= a[i];
                }
            }
            for (int i = l - 1; i <= l + 1; ++i) {
                if (used[i])continue;
                if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                    ans += a[i];
                    used[i] = 1;
                }
                if (a[i - 1] > a[i] && a[i + 1] > a[i]) {
                    ans -= a[i];
                    used[i] = 1;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}