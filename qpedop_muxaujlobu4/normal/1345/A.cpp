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
long long arr[Y];
long long ans[Y];
int n;
long long k;
bool f(long long v) {
    long long s = 0;
    for (int i = 0; i < n; ++i) {
        s += min(v, arr[i]);
    }
    return s >= k;
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
        int a, b;
        cin >> a >> b;
        if (max(a, b) >= 3) {
            if (min(a, b) == 1) {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
        else cout << "YES\n";
    }
    return 0;
}