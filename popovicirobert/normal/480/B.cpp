#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;

ll a[MAXN + 1];

map <ll, bool> mp;
ll l;

inline int get(int n, ll x) {
    for(int i = 1; i <= n; i++) {
        if(a[i] - x >= 0) {
            return a[i] - x;
        }
        if(a[i] + x <= l) {
            return a[i] + x;
        }
    }
}

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i, n;
    ll x, y;
    ios::sync_with_stdio(false);
    cin >> n >> l >> x >> y;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    bool okx = 0, oky = 0;
    for(i = 1; i <= n; i++) {
        if(mp[a[i] - x] == 1) {
            okx = 1;
        }
        if(mp[a[i] - y] == 1) {
            oky = 1;
        }
    }
    if(okx && oky) {
        cout << 0;
        return 0;
    }
    if(oky) {
        cout << 1 << "\n";
        cout << get(n, x);
        return 0;
    }
    if(okx) {
        cout << 1 << "\n";
        cout << get(n, y);
        return 0;
    }
    for(i = 1; i <= n; i++) {
        if(a[i] - x >= 0 && (mp[a[i] - x - y] || mp[a[i] - x + y])) {
           cout << 1 << "\n" << a[i] - x;
           return 0;
        }
        if(a[i] + x <= l && (mp[a[i] + x - y] || mp[a[i] + x + y])) {
            cout << 1 << "\n" << a[i] + x;
            return 0;
        }

    }
    cout << 2 << "\n";
    cout << get(n, x) << " " << get(n, y);
    //cin.close();
    //cout.close();
    return 0;
}