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
const long long INF = 1e17;
const int Y = 200100;
vector<int>Ed[Y];
long long a[Y];
long long b[Y];
long long c[Y];
long long cost[Y];
int mn[Y];
int pl[Y];
int n;
void dfs(int i, int p) {
    int tmp = 0;
    if (b[i] != c[i]) {
        if (b[i] == 1) {
            tmp++;
        }
        else {
            tmp--;
        }
    }
    for (auto x : Ed[i]) {
        if (x == p)continue;
        a[x] = min(a[x], a[i]);
        dfs(x, i);
        pl[i] += pl[x];
        mn[i] += mn[x];
        cost[i] += cost[x];
    }
    if (tmp == 1) {
        ++pl[i];
    }
    if (tmp == -1) {
        ++mn[i];
    }
    long long mp = min(pl[i], mn[i]);
    cost[i] += 2 * mp * a[i];
    pl[i] -= mp;
    mn[i] -= mp;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int>vi1, vi2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        vi1.push_back(b[i]);
        vi2.push_back(c[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        Ed[a].push_back(b);
        Ed[b].push_back(a);
    }
    sort(vi1.begin(), vi1.end());
    sort(vi2.begin(), vi2.end());
    for (int i = 0; i < n; ++i) {
        if (vi1[i] != vi2[i]) {
            cout << -1;
            return 0;
        }
    }
    dfs(0, -1);

    if (pl[0] != 0 || mn[0] != 0) {
        cout << -1;
        return 0;
    }
    cout << cost[0];
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