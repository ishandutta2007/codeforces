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
const long long INF = 100000000;
const int Y = 200100;
//const long long m = 1000000007;
char M[52][52];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    vector<pair<int, int>>gg;
    gg.push_back({ -1,0 });
    gg.push_back({ 1,0 });
    gg.push_back({ 0,-1 });
    gg.push_back({ 0,1 });
    while (t--) {
        int n, m;
        cin >> n >> m;
        int cG = 0, cB = 0;
        for (int i = 0; i <= m; ++i) {
            M[0][i] = M[n + 1][i] = '#';
        }
        for (int i = 0; i <= n; ++i) {
            M[i][0] = M[i][m + 1] = '#';
        }
        bool mt = false;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> M[i][j];
                if (M[i][j] == 'G') {
                    ++cG;
                    if (M[i - 1][j] == 'B' || M[i][j - 1] == 'B') {
                        mt = true;
                    }
                }
                if (M[i][j] == 'B') {
                    ++cB;
                    if (M[i - 1][j] == 'G' || M[i][j - 1] == 'G') {
                        mt = true;
                    }
                }
            }
        }
        if (cG == 0) {
            cout << "Yes\n";
            continue;
        }
        if (mt) {
            cout << "No\n";
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (M[i][j] == 'B') {
                    for (auto x : gg) {
                        int n1 = i + x.first, n2 = j + x.second;
                        if (M[n1][n2] == '.') {
                            M[n1][n2] = '#';
                        }
                    }
                }
            }
        }
        if (M[n][m] == '#') {
            cout << "No\n";
            continue;
        }
        queue<pair<int, int>>q;
        q.push({ n,m });
        while (!q.empty()) {
            int i, j;
            tie(i, j) = q.front();
            q.pop();
            for (auto x : gg) {
                int n1 = i + x.first, n2 = j + x.second;
                if (M[n1][n2] == '.') {
                    M[n1][n2] = '#';
                    q.push({ n1,n2 });
                }
                if (M[n1][n2] == 'G') {
                    M[n1][n2] = '#';
                    --cG;
                    q.push({ n1,n2 });
                }
            }
        }
        if (cG == 0) {
            cout << "Yes\n";
        }
        else cout << "No\n";
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