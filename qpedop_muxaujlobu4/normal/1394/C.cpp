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
int n;
int cB = 0, cN = 0;
long long dist = INF;
vector<pair<int, int>>st;
long long f2(int coB, int coN) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (st[i].first >= coB && st[i].second >= coN) {
            int d1 = st[i].first - coB, d2 = st[i].second - coN;
            res = max(res, max(d1, d2));
        }
        if (st[i].first < coB && st[i].second < coN) {
            int d1 = coB - st[i].first, d2 = coN - st[i].second;
            res = max(res, max(d1, d2));
        }
        if (st[i].first >= coB && st[i].second < coN) {
            int d1 = st[i].first - coB, d2 = coN - st[i].second;
            res = max(res, d1 + d2);
        }
        if (st[i].first < coB && st[i].second >= coN) {
            int d1 = coB - st[i].first, d2 = st[i].second - coN;
            res = max(res, d1 + d2);
        }
    }
    if (res < dist) {
        dist = res;
        cB = coB;
        cN = coN;
    }
   // cout << coB << " " << coN << " " << res << endl;
    return res;
}
int maxN = 0;
int f1(int coB) {
    int l = 0, r = maxN;
    if (coB == 0)l = 1;
    int m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
    for (; l + 2 < r; m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3) {
        if (f2(coB, m1) >= f2(coB, m2)) {
            l = m1;
        }
        else r = m2;
    }
    long long res = INF;
    for (int i = l; i <= r; ++i) {
        res = min(res, f2(coB, i));
    }
    return res;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    cin >> n;
    st.assign(n, { 0,0 });
    int maxB = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (auto x : s)if (x == 'B')++st[i].first;
        else ++st[i].second;
        maxB = max(maxB, st[i].first);
        maxN = max(maxN, st[i].second);
    }
    int l = 0, r = maxB;
    int m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
    for (; l + 2 < r; m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3) {
        if (f1(m1) >= f1(m2)) {
            l = m1;
        }
        else r = m2;
    }
    for (int i = l; i <= r; ++i)f1(i);
    cout << dist << "\n";
    for (int i = 0; i < cB; ++i)cout << 'B';
    for (int i = 0; i < cN; ++i)cout << 'N';
    return 0;
}