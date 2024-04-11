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
const int Y = 501;
vector<int>kl;
vector<pair<int, int>>seg;
int solve(int l, int r) {
    vector<int>dp(r - l + 1, 0);
    int y = 0;
    for (int i = l; i <= r; ++i) {
        while (y < seg.size() && seg[y].first < i)++y;
        while (y < seg.size() && seg[y].first == i) {
            if (seg[y].first == l && seg[y].second == r || seg[y].second > r) {
                ++y;
                continue;
            }
            if (kl[y] == -1) {
                kl[y] = 1 + solve(seg[y].first, seg[y].second);
            }
            int tmp = 0;
            if (i != l) {
                tmp += dp[i - l - 1];
            }
            dp[seg[y].second - l] = max(dp[seg[y].second - l], kl[y] + tmp);
            ++y;
        }
        if (i != l)dp[i - l] = max(dp[i - l], dp[i - l - 1]);
    }
    return dp.back();
}
int32_t main()
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
        vector<int>pts;
        seg.resize(n);
        kl.assign(n, -1);
        for (int i = 0; i < n; ++i) {
            cin >> seg[i].first >> seg[i].second;
            pts.push_back(seg[i].first);
            pts.push_back(seg[i].second);
        }
        sort(seg.begin(), seg.end());
        sort(pts.begin(), pts.end());
        pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
        for (auto& x : seg) {
            x.first = lower_bound(pts.begin(), pts.end(), x.first) - pts.begin();
            x.second = lower_bound(pts.begin(), pts.end(), x.second) - pts.begin();
        }
        cout << solve(0, (int)pts.size()) << "\n";
    }
    return 0;
}
/*
8 8
7 8 1 1
1 2 1 -1
2 3 1 -1
3 4 1 -1
4 1 1 -1
2 5 1 -10
5 6 1 -10
6 2 1 -10
7 8
*/
//freopen("points.in", "r", stdin);
//freopen("points.out", "w", stdout);

/* Tue Aug 04 2020 00:52:10 GMT+0300 (,  ) */