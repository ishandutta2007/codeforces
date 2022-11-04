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
const unsigned long long INF = 1e17;
const int INFi = 2e8;
const int Y = 200100;
const long long m = 998244353;
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
int f(long long n) {
    long long b = 1, e = 1000000000;
    while (b + 1 != e) {
        long long mid = (b + e) / 2;
        if (mid * 2 + (mid - 1) * mid / 2 * 3 <= n)b = mid;
        else e = mid;
    }
    return n - b * 2 - (b - 1) * b / 2 * 3;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        while (n > 1) {
            ++ans;
            n = f(n);
        }
        cout << ans << endl;
    }
    return 0;
}