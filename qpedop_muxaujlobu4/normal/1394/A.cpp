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
const int Y = 1000101;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    long long n, m, d;
    cin >> n >> d >> m;
    vector<long long>a1, a2, pr;
    pr.push_back(0);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long tmp;
        cin >> tmp;
        if (tmp > m) {
            a1.push_back(tmp);
        }
        else a2.push_back(tmp);
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    reverse(a1.begin(), a1.end());
    reverse(a2.begin(), a2.end());
    for (int i = 0; i < a2.size(); ++i)pr.push_back(pr.back() + a2[i]);
    long long s = 0;
    if (a1.size() == 0) {
        cout << pr.back();
        return 0;
    }
    for (int i = 0; i < a1.size(); ++i) {
        s += a1[i];
        long long tmp = (long long)n - (d + 1) * (i)-1;
        long long tmp1 = (long long)n - (d + 1) * (i + 1);
        if ((tmp1 <= a2.size() && a2.size() <= tmp || tmp <= a2.size()) && tmp >= 0) {
            if (tmp >= a2.size()) {
                ans = max(ans, s + pr.back());
            }
            else ans = max(ans, s + pr[tmp]);
        }
    }
    cout << ans;
    return 0;
}