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
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int n;
    cin >> n;
    vector<vector<long long>>dp(n);
    vector<string>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i].assign(a[i].size() + 1, 0);
    }
    dp[0].assign(a[0].size() + 1, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= a[i - 1].size(); ++j) {
            string s1 = "";
            for (int k = 0; k < a[i - 1].size(); ++k)if (j != k)s1.push_back(a[i - 1][k]);
            int y1 = 0, y2 = 0;
            bool check = true;
            for (int k = 0; k <= a[i].size(); ++k) {
                if (y2 == k)++y2;
                while (y1 < s1.size() && y2 < a[i].size() && s1[y1] == a[i][y2]) {
                    ++y1;
                    ++y2;
                    if (y2 == k)++y2;
                }
                if (y1 == s1.size() && y2 == a[i].size()) {
                    check = true;
                }
                else {
                    if (y1 == s1.size() && y2 != a[i].size()) {
                        check = true;
                    }
                    else {
                        if (y1 != s1.size() && y2 == a[i].size()) {
                            check = false;
                        }
                        else {
                            check = s1[y1] < a[i][y2];
                        }
                    }
                }
                if (check) {
                    dp[i][k] += dp[i - 1][j];
                    if (dp[i][k] >= m)dp[i][k] -= m;
                }
                if (y2 > k&& k < s1.length() && a[i][k] != s1[k]) {
                    y1 = y2 = k;
                }
                if (k + 1 == y2) {
                    --y2;
                }
            }
        }
    }
    long long ans = 0;
    for (auto x : dp.back())ans = (ans + x) % m;
    cout << ans << endl;
    return 0;
}