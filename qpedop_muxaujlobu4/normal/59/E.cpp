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
#include<bitset>
using namespace std;
//#define double long long;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
const double e = 0.0000005;
const double pi = 3.14159265359;
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
const long long INF = 10000000000000;
const int Y = 3001;
bool vis[Y][Y];
int pred[Y][Y];
long long cost[Y][Y];
vector<int>Ed[Y];
map<tuple<int,int,int>, bool>danger;
int main()
{
    srand(10241274216);
    cout.precision(10);
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n = getint<int>(), m = getint<int>(), k = getint<int>();
    for (int i = 0; i < m; ++i) {
        int a = getint<int>(), b = getint<int>();
        Ed[a].push_back(b);
        Ed[b].push_back(a);
    }
    for (int i = 0; i < k; ++i) {
        int a = getint<int>(), b = getint<int>(), c = getint<int>();
        danger[make_tuple(a,b,c)] = true;
    }
    queue<pair<int, int>>q;
    cost[0][1] = 0;
    q.push({ 1,0 });
    vis[0][1] = true;
    int ans = -1;
    int pr;
    while (!q.empty()) {
        int b, p;
        tie(b, p) = q.front();
        q.pop();
        if (b == n) {
            ans = cost[p][b];
            pr = p;
            break;
        }
        for (auto x : Ed[b]) {
            if (vis[b][x])continue;
            if (danger[make_tuple(p,b,x)])continue;
            vis[b][x] = true;
            cost[b][x] = cost[p][b] + 1;
            pred[b][x] = p;
            q.push({ x,b });
        }
    }
    cout << ans << "\n";
    if (ans == -1) {
        return 0;
    }
    vector<int>ViVod;
    int b = n;
    while (b != 1) {
        ViVod.push_back(b);
        int tmp = pr;
        pr = pred[pr][b];
        b = tmp;
    }
    ViVod.push_back(1);
    int sz = ViVod.size() - 1;
    for (int i = sz; i >= 0; --i) {
        cout << ViVod[i] << " ";
    }
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */

/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */

    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);