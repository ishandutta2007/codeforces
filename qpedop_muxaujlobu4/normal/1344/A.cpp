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
long long PW(long long et, long long b) {
    if (b == 0)return 1;
    long long tmp = PW(et, b / 2);
    tmp = (tmp * tmp) % m;
    if (b % 2 == 1)tmp = (tmp * et) % m;
    return tmp;
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
        vector<int>a(n);
        vector<int>b(n);
        bool gd = true;
        for (auto& x : a) {
            cin >> x;
            x = (x % n + n) % n;
        }
        for (int i = 0; i < n; ++i) {
            b[(i + a[i]) % n]++;
        }
        for (auto x : b)gd &= x == 1;
        if (gd)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}