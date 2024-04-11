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
const long long m = 998244353;
int st[Y];
int en[Y];
long long pw[Y];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    fill(begin(st), end(st), -1);
    fill(begin(en), end(en), -1);
    int n, mm;
    cin >> n >> mm;
    vector<int>a(n);
    vector<int>b(mm);
    pw[0] = 1;
    for (int i = 1; i < Y; ++i) {
        pw[i] = pw[i - 1] * 2 % m;
    }
    for (auto& x : a)cin >> x;
    for (auto& x : b)cin >> x;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int id = upper_bound(b.begin(), b.end(), a[i]) - b.begin() - 1;
        if (id == -1) {
            cout << 0;
            return 0;
        }
        if (b[id] == a[i]) {
            st[id] = i;
        }
        en[id] = i;
    }
    for (int i = 0; i < mm; ++i) {
        if (st[i] == -1) {
            cout << 0;
            return 0;
        }
    }
    for (int i = 1; i < mm; ++i) {
        if (st[i] <= en[i - 1]) {
            cout << 0;
            return 0;
        }
    }
    ans = 1;
    for (int i = 1; i < mm; ++i) {
        long long kl = st[i] - en[i - 1];
        ans = (ans * kl) % m;
    }
    cout << ans;
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