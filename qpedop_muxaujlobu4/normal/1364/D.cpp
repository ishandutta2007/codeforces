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
const long long INF = 10000000;
const int Y = 200100;
const long long mod = 1000000007;
vector<int>Ed[Y];
int cl[Y];
int vs[Y];
int p[Y];
int cost[Y];
stack<int>st;
int len = INF;
int stW = -1;
int enW = -1;
vector<int>c1;
vector<int>c2;
void dfs(int i) {
    vs[i] = 1;
    cl[i] = st.size();
    st.push(i);
    for (auto x : Ed[i]) {
        if (vs[x] == 2)continue;
        if (vs[x] == 1) {
            int tmp = cl[i] - cl[x] + 1;
            if (tmp < len && tmp != 2) {
                len = tmp;
                stW = x;
                enW = i;
            }
        }
        if (vs[x] == 0) {
            dfs(x);
        }
    }
    vs[i] = 2;
    st.pop();
}
void dfs2(int i, int cv) {
    vs[i] = 1;
    if (cv == 0) {
        c1.push_back(i);
    }
    else c2.push_back(i);
    for (auto x : Ed[i]) {
        if (vs[x] == 1)continue;
        dfs2(x, 1 - cv);
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        Ed[a].push_back(b);
        Ed[b].push_back(a);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)vs[i] = 0;
    if (len == INF) {
        dfs2(1, 1);
        cout << 1 << endl;
        if (c1.size() > c2.size()) {
            for (int i = 0; i < (k + 1) / 2; ++i) {
                cout << c1[i] << " ";
            }
        }
        else {
            for (int i = 0; i < (k + 1) / 2; ++i) {
                cout << c2[i] << " ";
            }
        }
        return 0;
    }
    for (int i = 1; i <= n; ++i)cost[i] = INF;
    cost[stW] = 1;
    vs[stW] = 1;
    queue<int>q;
    q.push(stW);
    p[stW] = -1;
    while (!q.empty()) {
        int b = q.front();
        q.pop();
        for (auto x : Ed[b]) {
            if (b == stW && x == enW)continue;
            if (!vs[x]) {
                vs[x] = 1;
                cost[x] = cost[b] + 1;
                p[x] = b;
                q.push(x);
            }
        }
    }
    vector<int>cir;
    while (enW != stW) {
        cir.push_back(enW);
        enW = p[enW];
    }
    cir.push_back(stW);
    if (cir.size() <= k) {
        cout << 2 << endl;
        cout << cir.size() << endl;
        for (auto x : cir)cout << x << " ";
        return 0;
    }
    cout << 1 << endl;
    for (int j = 0; j < (k + 1) / 2; ++j) {
        cout << cir[2 * j] << " ";
    }
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