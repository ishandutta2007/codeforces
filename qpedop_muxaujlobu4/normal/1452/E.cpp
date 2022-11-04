#pragma comment(linker, "/STACK:9759095000")
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
const long long INF = 1e9;
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 1070100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
vector<vector<int>>G;
vector<int>cost;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    vector<pair<int, int>>seg(m);
    for (int i = 0; i < m; ++i) {
        cin >> seg[i].first >> seg[i].second;
        --seg[i].first;
        seg[i].second;
    }
    for (int i = 0; i < n; ++i) {
        int ta = 0;
        int l = i, r = i + k;
        vector<pair<int, int>>fl(n + 1);
        for (auto x : seg) {
            int slen = max(0, min(r, x.second) - max(l, x.first));
            ta += max(0, min(r, x.second) - max(l, x.first));
            if (x.second <= r) {
                continue;
            }
            int l1 = x.first - k + slen;
            int l2 = min(x.second - k, x.first);
            if (l1 >= l2)continue;
            ++fl[l1].second;
            --fl[l2].second;
            l2 = max(x.second - k, x.first);
            int l3 = x.second - slen;
            --fl[l2].second;
            ++fl[l3].second;
        }
        int s = 0;
        int k = 0;
        for (auto& x : fl) {
            k += x.second;
            s += k;
            x.first = s;
        }
        for (auto x : fl)ans = max(ans, x.first + ta);
    }
    cout << ans << endl;
    return 0;
}