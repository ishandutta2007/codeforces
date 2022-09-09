#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define all(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
typedef long long LL;

int n, l, x, y;
vector <int> v;

vector <int> check(int len) {
    vector <int> ret;
    for (int i = 0; i < n; ++i) {
        vector <int>::iterator it = lower_bound(all(v), v[i] + len);
        if (it != v.end() && (*it) == v[i] + len) {
            ret.puba(i);
        }
    }
    return ret;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n >> l >> x >> y;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        v.puba(num);
    }

    if (szof(check(x)) && szof(check(y))) {
        cout << 0 << endl;
        return 0;
    }
    vector <int> tmp = check(x + y);
    if (szof(tmp)) {
        cout << 1 << endl << v[tmp[0]] + x << endl;
        return 0;
    }

    tmp = check(y - x);

    for (int i = 0; i < szof(tmp); ++i) {
        if (v[tmp[i]] >= x) {
            cout << 1 << endl << v[tmp[i]] - x << endl;
            return 0;
        }
        if (l - v[tmp[i]] >= y) {
            cout << 1 << endl << v[tmp[i]] + y << endl;
            return 0;
        }
    }

    if (szof(check(x))) {
        cout << 1 << endl << y << endl;
        return 0;
    }
    if (szof(check(y))) {
        cout << 1 << endl << x << endl;
        return 0;
    }

    cout << 2 << endl << x << " " << y << endl;

    return 0;
}