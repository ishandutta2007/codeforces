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
const int Y = 2100;
const long long mod = 1000000007;
long long c[Y];
long long c2[Y];
bool td[Y];
bool nt[Y];
long long mv[Y];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int>f(m);
    vector<int>t(m);
    vector<int>w(m);
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        cin >> f[i] >> t[i] >> w[i];
        --f[i];
        --t[i];
    }
    td[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (td[f[j]]) {
                c2[t[j]] = max(c2[t[j]], c[f[j]] + w[j]);
                nt[t[j]] = true;
            }
            if (td[t[j]]) {
                c2[f[j]] = max(c2[f[j]], c[t[j]] + w[j]);
                nt[f[j]] = true;
            }
        }
        long long mx = 0;
        for (int j = 0; j < n; ++j) {
            c[j] = c2[j];
            td[j] = nt[j];
            nt[j] = false;
            c2[j] = 0;
            if (td[j]) {
                mx = max(mx, c[j]);
            }
        }
        ans += mx;
        if (i + 1 == q) {
            cout << ans % mod;
            return 0;
        }
    }
    ans %= mod;
    vector<pair<long long, long long>>deb;
    for (int j = 0; j < m; ++j) {
        pair<long long, long long> tmp = { w[j],0 };
        if (td[f[j]]) {
            tmp.second = max(tmp.second, c[f[j]]);
        }
        if (td[t[j]]) {
            tmp.second = max(tmp.second, c[t[j]]);
        }
        if (tmp.second != 0)deb.push_back(tmp);
    }
    q -= n;
    int sz = deb.size();
    vector<pair<long long, int>>gg;
    gg.push_back({ q + 1,-1 });
    for (int i = 0; i < sz; ++i) {
        int c = 0;
        for (int j = 0; j < sz; ++j) {
            if (deb[j].first > deb[i].first&& deb[j].second > deb[i].second)++c;
        }
        if (c)continue;
        long long mv = 1;
        long long ver = q + 1;
        for (int j = 0; j < sz; ++j) {
            if (deb[i] == deb[j])continue;
            if (deb[i].first < deb[j].first) {
                swap(j, i);
                long long mmm = (deb[j].second - deb[i].second + deb[i].first - deb[j].first - 1) / (deb[i].first - deb[j].first);
                swap(j, i);
                --mmm;
                ver = min(ver, mmm);
            }
            if (deb[i].first > deb[j].first) {
                long long mmm = (deb[j].second - deb[i].second + deb[i].first - deb[j].first - 1) / (deb[i].first - deb[j].first);
                mv = max(mv, mmm);
            }
            if (deb[i].first == deb[j].first) {
                if (deb[j].second > deb[i].second) {
                    mv = q + 1;
                    break;
                }
            }
        }
        if (ver < mv)continue;
        gg.push_back({ mv,i });
    }
    sort(gg.begin(), gg.end());
    long long ob = (mod + 1) / 2;
    for (int i = 0; i < gg.size(); ++i) {
        int j = i + 1;
        int jj = gg[i].second;
        long long st = (deb[jj].second + deb[jj].first * gg[i].first % mod) % mod;
        long long en = (deb[jj].second + deb[jj].first * (gg[i + 1].first - 1) % mod) % mod;
        ans = (ans + (gg[i + 1].first - gg[i].first) * (st + en) % mod * ob % mod) % mod;
        if (gg[j].first == q + 1) {
            break;
        }
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