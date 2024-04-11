#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e15 + 7;

int res = 0;

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

struct seg {
    int ax, ay, cx, cy, k;

    seg() {}
};

set<pii> used;

bool check(seg a, seg b) {

    bool rev = false;
    if (a.cx == 0) {
        swap(a.cx, a.cy);
        swap(a.ax, a.ay);
        swap(b.cx, b.cy);
        swap(b.ax, b.ay);
        rev = true;
    }   

    int num1 = (a.ay - b.ay) * a.cx + a.cy * (b.ax - a.ax); // (5) * 1 - 1 * (1) = 4
    int num2 = b.cy * a.cx - b.cx * a.cy; // -1 * 1 - 1 = -2
    //cout << num1 << " " << num2 << endl;
    if (num2 == 0 || num1 % num2 != 0) return false;

    int k2 = num1 / num2; // 3
    //cout << k2 << endl;

    int num3 = (b.ax + k2 * b.cx - a.ax); // 2
    if (num3 % a.cx != 0) return false;
    int k1 = num3 / a.cx; // 2

    //cout << k1 << endl;

    if (k1 * a.k < 0 || k2 * b.k < 0) return false;
    if (abs(k1) > abs(a.k) || abs(k2) > abs(b.k)) return false;


    int x = k1 * a.cx + a.ax, y = k1 * a.cy + a.ay;
    if (rev) swap(x, y);

    if (used.count(mp(x, y))) {
        return false;
    }

    used.emplace(x, y);

    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<seg> a(n);
    int res = 0;
    for(int i = 0;i < n;i++) {
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        a[i].k = abs(gcd(bx - ax, by - ay));
        a[i].ax = ax, a[i].ay = ay;
        a[i].cx = (bx - ax) / a[i].k, a[i].cy = (by - ay) / a[i].k;

        //cout << a[i].ax << " " << a[i].ay << " " << a[i].cx << " " << a[i].cy << " " << a[i].k << endl;

        res += a[i].k + 1;

        for(int j = 0;j < i;j++) {
            if (check(a[i], a[j])) res--;
        }
        used.clear();
    }
    cout << res;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    solve();
}