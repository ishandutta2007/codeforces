#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<ctime>
#include<random>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>

void boostIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const int Y = 200100, inf = 1e8;
const long long m = 998244353;
template<typename T> T getint() {
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
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
int tree[Y * 4];
int sz = 1;
void PUSH(int id, int val) {
    id += sz;
    while (id) {
        tree[id] = min(tree[id], val);
        id /= 2;
    }
}
int get(int ql, int qr, int v, int tl, int tr) {
    if (ql <= tl && tr <= qr)return tree[v];
    int res = inf, mid = (tr + tl) / 2;
    if (ql <= mid)res = min(res, get(ql, qr, 2 * v, tl, mid));
    if (qr > mid)res = min(res, get(ql, qr, 2 * v + 1, mid + 1, tr));
    return res;
}
int main()
{
    boostIO();
    int t;
    cin >> t;
    while (t--) {
        int n; long long k;
        cin >> n >> k;
        vector<long long>a(n);
        map<int, int>f;
        map<int, int>s;
        for (auto& x : a)cin >> x;
        bool res = false;
        if (n == 1) {
            res = a[0] == k;
        }
        else {
            vector<int>pr(n+1);
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] == k)++cnt;
                if (a[i] >= k)pr[i + 1] = pr[i] + 1;
                else pr[i + 1] = pr[i] - 1;
                ++s[pr[i + 1]];
            }
            if (cnt == 0) {
                cout << "no\n";
                continue;
            }
            for (int i = 0; i < n; ++i) {
                ++f[pr[i]];
                --s[pr[i + 1]];
                if (a[i] >= k) {
                    int kk = pr[i + 1];
                    if (s[kk] != 0 || s[kk + 1] != 0)res = true;
                    if (f[kk - 2] != 0 || f[kk - 1] != 1)res = true;
                }
            }
        }
        if (res)cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}