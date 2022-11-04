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
const int Y = 500;
vector<int>ans;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    vector<int>a(n);
    for (auto& x : a)cin >> x;
    sort(a.begin(), a.end());
    for (int x = 1; x <= 2000; ++x) {
        bool gd = true;
        for (int i = 0; i < n; ++i) {
            if (x + i < a[i]) {
                gd = false;
                break;
            }
            int ln = upper_bound(a.begin(), a.end(), x + i) - a.begin();
            ln -= i;
            if (ln % p == 0) {
                gd = false;
                break;
            }
        }
            if (gd) {
                ans.push_back(x);
            }
    }
    cout << ans.size() << endl;
    for (auto x : ans)cout << x << " ";
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