#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define sz(a) ((int) a.size())
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;

const int inf = 1e15;

struct w {
    int fi, se, id;

    w() {}

    w(int fi, int se, int id) : fi(fi), se(se), id(id) {}

    bool operator< (const w& a) const {
        return id < a.id;
    }
};

int n;
w a[3];

bool f1(vector<vector<int>>& b) {
    if (a[0].se != n || a[1].se != n || a[2].se != n) return false;
    for(int j = 0;j < n;j++) {
        for(int i = a[0].fi;i < a[0].fi + a[1].fi;i++)
            b[i][j] = 1;

        for(int i = a[0].fi + a[1].fi;i < n;i++) 
            b[i][j] = 2;
    }
    return true;
}

bool f2(vector<vector<int>>& b) {
    if (a[0].se + a[1].se != n || a[0].fi != a[1].fi || a[2].se != n) return false;
    for(int i = 0;i < a[0].fi;i++)
        for(int j = a[0].se;j < n;j++)
            b[i][j] = 1;

    for(int i = a[0].fi;i < n;i++)
        for(int j = 0;j < n;j++)
            b[i][j] = 2;
    return true;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(3);
    
    for(int i = 0;i < 3;i++) {
        cin >> a[i].fi >> a[i].se;
        a[i].id = i;
        n += a[i].fi * a[i].se;
    }
    if ((int) sqrt(n) * (int) sqrt(n) != n) {
        cout << -1;
        return 0;
    }
    n = sqrt(n);

    vector<vector<int>> res(n, vector<int>(n));

    for(int it = 0;it < 6;it++) {
        for(int mask = 0;mask < 8;mask++) {
            for(int i = 0;i < 3;i++)
                if (mask >> i & 1) swap(a[i].fi, a[i].se);

            if (f1(res) || f2(res)) {
                cout << n << endl;
                for(int i = 0;i < n;i++) {
                    for(int j = 0;j < n;j++)
                        cout << (char)('A' + a[res[i][j]].id);
                    cout << endl;
                }
                return 0;
            }

            for(int i = 0;i < 3;i++)
                if (mask >> i & 1) swap(a[i].fi, a[i].se);
        }
        next_permutation(a, a + 3);
    }
    cout << -1;
}