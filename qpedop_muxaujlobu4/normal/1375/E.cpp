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
long long INF = 1e17;
const long long m = 1000000007;
const int Y = 200100;
int id[Y];
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int>a(n);
    set<int>vs;
    for (auto& x : a) {
        cin >> x;
        x += 2000;
        vs.insert(x);
    }
    int j = 0;
    for (auto x : vs) {
        for (int i = 0; i < n; ++i) {
            if (a[i] == x) {
                a[i] = j;
                id[j] = i;
                ++j;
            }
        }
    }
    vector<pair<int, int>>vd;
    for (int i = n - 1; i >= 0; --i) {
        while (a[i] != i) {
            int i1 = id[a[i] + 1], i2 = id[a[i]];
            swap(id[a[i] + 1], id[a[i]]);
            swap(a[i1], a[i2]);
            vd.push_back({ i1 + 1,i2 + 1 });
        }
    }
    cout << vd.size() << "\n";
    for (auto x : vd)cout << x.first << " " << x.second << "\n";
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