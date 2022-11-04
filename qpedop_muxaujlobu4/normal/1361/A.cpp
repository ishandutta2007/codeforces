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
//#define int long long
using namespace std;
int gcd(int i, int j) {
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
const long long INF = (int)1e7;
const int Y = 500100;
pair<int, int> ans[Y];
vector<int>Ed[Y];
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        Ed[a].push_back(b);
        Ed[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> ans[i].first;
        ans[i].second = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (auto x : Ed[i]) {
            if (ans[x].first == ans[i].first) {
                cout << -1;
                return 0;
            }
        }
    }
    ans[0] = { 0,0 };
    for (int i = 1; i <= n; ++i) {
        bitset<Y>ar;
        int ct = 0;
        for (auto x : Ed[i]) {
            int to = ans[x].first;
            if (to >= ans[i].first || ar[to]) {
                continue;
            }
            ar[to] = true;
            ++ct;
        }
        if (ct + 1 != ans[i].first) {
            cout << -1;
            return 0;
        }
    }
    sort(ans + 1, ans + 1 + n);
    for (int i = 1; i <= n; ++i)cout << ans[i].second << " ";
    return 0;
}
//freopen("painter.in", "r", stdin);
//freopen("painter.out", "w", stdout);
/*
3
ooo
o..
o..
*/
/* Fri May 15 2020 19:54:42 GMT+0300 (MSK) */

/* Wed May 20 2020 19:33:48 GMT+0300 (MSK) */