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
//const long long m = 1000000007;
const int Y = 200100;
vector<pair<long long, int>>a, b, ba, no;
pair<long long, vector<int>>dp[Y];
int n, m, k;
long long f(int kl) {
    if (dp[kl].first != -1)return dp[kl].first;
    long long res = 0;
    vector<int>id;
    for (int i = 0; i < kl; ++i) {
        res += ba[i].first;
        id.push_back(ba[i].second);
    }
    vector<pair<long long, int>>fg = no;
    for (int i = kl; i < ba.size(); ++i)fg.push_back(ba[i]);
    int need = k - kl;
    for (int i = 0; i < need; ++i) {
        res += a[i].first;
        id.push_back(a[i].second);
        res += b[i].first;
        id.push_back(b[i].second);
    }
    for (int i = need; i < a.size(); ++i) {
        fg.push_back(a[i]);
    }
    for (int i = need; i < b.size(); ++i) {
        fg.push_back(b[i]);
    }
    sort(fg.begin(), fg.end());
    need = m - (int)id.size();
    for (int i = 0; i < need; ++i) {
        res += fg[i].first;
        id.push_back(fg[i].second);
    }
    dp[kl] = { res,id };
    return res;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        int tmp, aa, bb;
        cin >> tmp >> aa >> bb;
        if (aa == 0) {
            if (bb == 0) {
                no.push_back({ tmp,i + 1 });
            }
            else {
                b.push_back({ tmp,i + 1 });
            }
        }
        else {
            if (bb == 0) {
                a.push_back({ tmp,i + 1 });
            }
            else {
                ba.push_back({ tmp,i + 1 });
            }
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(ba.begin(), ba.end());
    sort(no.begin(), no.end());
    if (a.size() + ba.size() < k || b.size() + ba.size() < k || 2 * k - (int)ba.size() > m) {
        cout << -1;
        return 0;
    }
    int l = 0, r = min((int)ba.size(), k);
    while (a.size() + l < k || b.size() + l < k || 2 * k - l > m)++l;
    for (int i = 0; i <= r; ++i)dp[i].first = -1;
    int m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
    for (int i = 0; i < 50 && l + 2 < r; ++i, m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3) {
        if (f(m1) >= f(m2)) {
            l = m1;
        }
        else {
            r = m2;
        }
    }
    int y = l;
    long long res = f(l);
    if (f(r) < res) {
        res = f(r);
        y = r;
    }
    r = m1;
    if (f(r) < res) {
        res = f(r);
        y = r;
    }
    r = m2;
    if (f(r) < res) {
        res = f(r);
        y = r;
    }
    cout << res << endl;
    for (auto x : dp[y].second)cout << x << " ";
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