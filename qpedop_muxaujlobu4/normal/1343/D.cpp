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
const unsigned long long INF = 10000000000000000;
const int Y = 400100;
const long long m = 1000000007;
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
bool cmp(long long a, long long b) {
    return a % 2 < b % 2;
}
int n, k;
long long sm[Y];
long long go[Y];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (int i = 1; i <= 2 * k; ++i) {
            go[i] = 0;
            sm[i] = 0;
        }
        for (int i = 0; i < n / 2; ++i) {
            long long a = arr[i], b = arr[n - i - 1];
            int m1 = min(a, b);
            go[1] += 2;
            if (a == b && a == 1) {
                go[2] -= 2;
            }
            else {
                go[m1 + 1] -= 1;
                go[a + b] -= 1;
            }
            long long m2 = max(a, b);
            go[m2 + k + 1] += 1;
            go[a + b + 1] += 1;
        }
        long long tm = 0;
        for (int i = 1; i <= 2 * k; ++i) {
            tm += go[i];
            sm[i] = tm;
        }
        long long res = sm[1];
        for (int i = 1; i <= 2 * k; ++i)res = min(res, sm[i]);
        cout << res << "\n";
    }
    return 0;
}