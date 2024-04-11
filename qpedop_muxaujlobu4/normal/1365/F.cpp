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
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        vector<int>b(n);
        for (auto& x : a)cin >> x;
        for (auto& x : b)cin >> x;
        if (n % 2 == 1 && a[n / 2] != b[n / 2]) {
            cout << "No\n";
            continue;
        }
        vector<pair<int, int>>aa;
        vector<pair<int, int>>bb;
        bool res = true;
        for (int i = 0; i < n / 2; ++i) {
            int f = a[i], s = a[n - i - 1];
            if (f < s)swap(f, s);
            aa.push_back({ f,s });
            f = b[i], s = b[n - i - 1];
            if (f < s)swap(f, s);
            bb.push_back({ f,s });
        }
        sort(bb.begin(), bb.end());
        sort(aa.begin(), aa.end());
        for (int i = 0; i < aa.size(); ++i) {
            res &= (aa[i] == bb[i]);
        }
        if (res)cout << "Yes\n";
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