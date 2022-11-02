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

void f(int& a, int& b) {
    int c = min(a, b);
    a -= c;
    b -= c;
}

int f1(vector<pii> a) {
    int res = inf;

    vector<int> c1(3), c2(3);
    iota(all(c1), 0);
    iota(all(c2), 0);

    while(next_permutation(all(c1))) {
        while(next_permutation(all(c2))) {

            bool bad = false;
            for(int i = 0;i < 3;i++)
                if (c1[i] == c2[i]) bad = true;
            if (bad) continue;

            vector<pii> b(3);
            for(int i = 0;i < 3;i++)
                b[i] = {a[i].fi, a[i].se};

            for(int i = 0;i < 3;i++) {
                //cout << c1[i] << " " << c2[i] << endl;

                f(b[c1[i]].fi, b[c2[i]].se);
                f(b[c1[i]].fi, b[3 - c1[i] - c2[i]].se);
            }

            res = min(res, b[0].fi + b[1].fi + b[2].fi);
        }
    }
    return res;
}

int f2(int a1, int a2, int a3, int b1, int b2, int b3) {
    return min(a3, b1) + min(a2, b3) + min(a1, b2);
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, a1, a2, a3, b1, b2, b3;
    cin >> n >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    cout << f1({mp(a1, b2), mp(a2, b3), mp(a3, b1)}) << " " << f2(a1, a2, a3, b1, b2, b3);
}