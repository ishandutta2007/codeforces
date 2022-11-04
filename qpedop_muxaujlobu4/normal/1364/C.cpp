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
const long long INF = 1000000;
const int Y = 200100;
const long long mod = 1000000007;
bool vis[INF + 1];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int>a(n);
    for (auto& x : a) {
        cin >> x;
        vis[x] = true;
    }
    set<int>InA, NA;
    for (int i = 0; i <= n; ++i) {
        if (vis[i])InA.insert(i);
        else NA.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] > i + 1) {
            cout << -1;
            return 0;
        }
    }
    vector<int>b;
    for (int i = 0; i < n; ++i) {
        if (InA.size() == 0) {
            b.push_back(*NA.begin());
            NA.erase(NA.begin());
            continue;
        }
        if (*InA.begin() == a[i]) {
            b.push_back(*NA.begin());
            NA.erase(NA.begin());
            continue;
        }
        else {
            b.push_back(*InA.begin());
            InA.erase(InA.begin());
            continue;
        }
    }
    for (auto x : b)cout << x << " ";
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