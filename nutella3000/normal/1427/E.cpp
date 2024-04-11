#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long double ld;

const int inf = 1e15;

int gcd(int x, int y, int& a, int& b) {
    if (y == 0) {
        a = 1;
        b = 0;
        return x;
    }
    int a1, b1;
    int res = gcd(y, x % y, a1, b1);
    a = b1;
    b = a1 - (x / y) * b1;
    return res;
}

vector<pii> res1;
vector<int> res2;

void two_pow(int a) {
    while(a < 2e18) {
        res1.emplace_back(a, a);
        res2.emplace_back(1);
        a *= 2;
    }
}

int find_y(int x) {
    int temp = x;
    int num = 1;
    while(temp > 0) {
        num *= 2;
        temp /= 2;
    }
    num /= 2;
    res1.emplace_back(x, num * x);
    res2.emplace_back(2);
    int y = (x ^ (num * x));
    return y;
}

void binmul(int x, int c) {
    int num = x, res = 0;
    while(c > 0) {
        if (c & 1) {
            if (res != 0) {
                res1.emplace_back(res, num);
                res2.emplace_back(1);
            }
            res += num;
        }
        c /= 2;
        num *= 2;
    }
}

void solve() {
    int x;
    cin >> x;
    two_pow(x);
    int y = find_y(x);
    two_pow(y);
    int a, b;
    int chk = gcd(x, y, a, b);

    if (chk != 1) {
        cout << x << " " << y << endl;
    }

    a = abs(a);
    b = abs(b);

    binmul(x, a);
    binmul(y, b);

    int r1 = x * a, r2 = y * b;

    if ((r1 ^ r2) != 1) {
        res1.emplace_back(r1, x);
        res2.emplace_back(1);

        res1.emplace_back(r2, x);
        res2.emplace_back(1);

        r1 += x; r2 += x;
    }

    if ((r1 ^ r2) != 1) {
        cout << r1 << " " << r2 << endl;
    }

    res1.emplace_back(r1, r2);
    res2.emplace_back(2);

    cout << res1.size() << endl;
    for(int i = 0;i < res1.size();i++) {
        cout << res1[i].fi << (res2[i] == 1 ? " + " : " ^ ") << res1[i].se << endl;
    }
}




signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}