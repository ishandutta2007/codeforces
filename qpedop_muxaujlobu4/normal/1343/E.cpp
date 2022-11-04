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
long long arr[Y];
vector<int>Ed[Y];
long long p[Y];
long long cost1[Y];
long long cost2[Y];
long long cost3[Y];
bool vis[Y];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        for (int i = 1; i <= m; ++i)cin >> p[i];
        sort(p + 1, p + 1 + m);
        for (int i = 1; i <= n; ++i) {
            Ed[i].clear();
        }
        for (int i = 1; i <= m; ++i) {
            p[i] = p[i - 1] + p[i];
        }
        for (int i = 0; i < m; ++i) {
            int d, dd;
            cin >> d >> dd;
            Ed[d].push_back(dd);
            Ed[dd].push_back(d);
        }
        for (int i = 1; i <= n; ++i) {
            cost1[i] = INF;
            cost2[i] = INF;
            cost3[i] = INF;
        }
        queue<int>q;
        for (int i = 1; i <= n; ++i)vis[i] = false;
        cost1[a] = 0;
        q.push(a);
        vis[a] = true;
        while (!q.empty()) {
            int d = q.front();
            q.pop();
            for (auto x : Ed[d]) {
                if (!vis[x]) {
                    cost1[x] = cost1[d] + 1;
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
        for (int i = 1; i <= n; ++i)vis[i] = false;
        cost2[b] = 0;
        q.push(b);
        vis[b] = true;
        while (!q.empty()) {
            int d = q.front();
            q.pop();
            for (auto x : Ed[d]) {
                if (!vis[x]) {
                    cost2[x] = cost2[d] + 1;
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
        for (int i = 1; i <= n; ++i)vis[i] = false;
        cost3[c] = 0;
        q.push(c);
        vis[c] = true;
        while (!q.empty()) {
            int d = q.front();
            q.pop();
            for (auto x : Ed[d]) {
                if (!vis[x]) {
                    cost3[x] = cost3[d] + 1;
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
        long long res = 1e17;
        for (int i = 1; i <= n; ++i) {
            int tm = cost1[i] + cost2[i] + cost3[i];
            if (cost1[i] == INF || cost2[i] == INF || cost3[i] == INF)continue;
            if (tm > m)continue;
            long long s = p[tm];
            s += p[cost2[i]];
            res = min(res, s);
        }
        cout << res << "\n";
    }
    return 0;
}