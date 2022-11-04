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
int li[Y];
bool vs[Y];
vector<int>Ed[Y];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    vector<int>nb;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            Ed[i].clear();
            vs[i] = true;
            li[i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            Ed[a].push_back(b);
        }
        vector<int>v;
        for (int i = 1; i <= n; ++i) {
            if (li[i] == 2) {
                v.push_back(i);
                continue;
            }
            else {
                for (auto x : Ed[i])li[x] = max(li[x], li[i] + 1);
            }
        }
        cout << v.size() << "\n";
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
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