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
const unsigned long long INF = 1e17;
const int INFi = 2e7;
const int Y = 200100;
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
struct Cyst {
    long long a;
    long long b;
    Cyst(long long A = 0, long long B = 0) {
        a = A;
        b = B;
    }
};
bool dp[501][501];
Cyst arr[501];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    dp[0][0] = true;
    int n, k;
    cin >> n >> k;
    long long cs = 0, csa = 0, csb = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].a >> arr[i].b;
        cs += arr[i].a + arr[i].b;
    }
    for (int i = 1; i <= n; ++i) {
        csb += arr[i].b;
        csa += arr[i].a;
    }
    vector<Cyst>tt;
    for (int i = 0; i < k; ++i)tt.push_back(Cyst(i, (k - i) % k));
    for (int i = 1; i <= n; ++i) {
        for (int ta = 0; ta < k; ++ta) {
            for (auto x : tt) {
                if (dp[i][ta] || x.a > arr[i].a)break;
                if (x.b > arr[i].b)continue;
                dp[i][ta] |= dp[i - 1][(ta + k - (arr[i].a - x.a) % k) % k];
            }
        }
    }
    long long mx = 0;
    for (int i = 0; i < k; ++i) {
        if (dp[n][i]) {
            long long tmp1 = (csa - i + k) % k;
            long long tmp2 = (k - tmp1) % k;
            long long ta = 0;
            if (tmp1 + tmp2 == k)++ta;
            ta += (csa - tmp1) / k + (csb - tmp2) / k;
            mx = max(mx, ta);
        }
    }
    cout << mx;
    return 0;
}