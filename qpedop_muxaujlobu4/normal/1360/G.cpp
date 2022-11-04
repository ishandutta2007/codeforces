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
const long long INF = 100000000;
const int Y = 2000100;
//const long long m = 1000000007;
char mt[51][51];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        if (n * a != b * m) {
            cout << "NO\n";
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                mt[i][j] = '0';
            }
        }
        priority_queue<pair<int, int>>q;
        for (int i = 1; i <= m; ++i) {
            q.push({ b,i });
        }
        for (int i = 1; i <= n; ++i) {
            vector <pair<int, int>>vd;
            for (int j = 1; j <= a; ++j) {
                vd.push_back(q.top());
                q.pop();
            }
            for (auto x : vd) {
                mt[i][x.second] = '1';
                --x.first;
                q.push(x);
            }
        }
        cout << "YES\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j)cout << mt[i][j];
            cout << "\n";
        }
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