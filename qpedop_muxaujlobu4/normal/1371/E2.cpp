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
const int Y = 100500;
vector<long long>ans;
map<long long, int> arr;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    long long n, p;
    cin >> n >> p;
    vector<long long>a(n);
    for (auto& x : a)cin >> x;
    sort(a.begin(), a.end());
    int st = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] - i > 0) {
            ++arr[0];
            --arr[a[i] - i];
            st = max(st, (int)a[i] - i);
        }
    }
    ++arr[a.back()];
    for (int i = 0, j = p - 1; j < n; ++i, ++j) {
        if (j + 1 == n || a[j] != a[j + 1]) {
            ++arr[a[j] - i];
            if (j + 1 != n)--arr[a[j + 1] - i];
        }
    }
    long long ls = -1;
    long long s = 0;
    int ct = 0;
    for (auto x : arr) {
        if (ct != 0 && s == 0) {
            for (long long i = ls; i < x.first; ++i)ans.push_back(i);
        }
        ++ct;
        s += x.second;
        ls = x.first;
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