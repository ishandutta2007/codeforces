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
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>>v;
    long long x = 0, y = 0;
    v.push_back({ x,y });
    for (int i = 0; i <= n; ++i) {
        v.push_back({ x + 1,y });
        v.push_back({ x + 2,y });
        v.push_back({ x + 2,y + 1 });
        v.push_back({ x + 2,y + 2});
        v.push_back({ x,y + 1});
        v.push_back({ x,y + 2});
        v.push_back({ x + 1,y + 2});
        x += 2;
        y += 2;
    }
    cout << v.size() << "\n";
    for (auto x : v)cout << x.first << " " << x.second << "\n";
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