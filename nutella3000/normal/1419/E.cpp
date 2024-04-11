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

int n;
vector<pii> p;
set<int> used;
vector<int> res;

void scan() {
    cin >> n;
    for(int i = 2; i * i <= n;i++) {
        if (n % i != 0) continue;
        int cnt = 0;
        while(n % i == 0) {
            cnt++;
            n /= i;
        }
        p.emplace_back(i, cnt);
    }
    if (n != 1) {
        p.emplace_back(n, 1);
    }
    //for(auto i : p)
    //    cout << i.fi << " " << i.se << endl;
}

void rec(int id, int num) {
    if (id == p.size()) {
        if (used.count(num)) return;
        res.emplace_back(num);
        return;
    }

    for(int i = 0;i <= p[id].se;i++) {
        rec(id + 1, num);
        num *= p[id].fi;
    }
}

void solve() {
    p.clear();
    used.clear();
    res.clear();

    scan();
    if (sz(p) == 2 && p[0].se == 1 && p[1].se == 1) {
        cout << p[0].fi << " " << p[1].fi << " " << p[0].fi * p[1].fi << endl << 1 << endl;
        return;
    }   

    //cout << "bef" << endl;

    for(int i = sz(p) - 1;i >= 0;i--) {

        if (i != sz(p) - 1) {
            int temp = p[i].fi * p[i + 1].fi;
            res.emplace_back(temp);
            used.emplace(temp);
        }

        int num = 1;
        for(int j = 1;j <= p[i].se;j++) {
            num *= p[i].fi;
            //cout << "bbb" << endl;
            rec(i + 1, num);
            //cout << "ccc" << endl;
        }
    }

    for(int i : res)
        cout << i << " ";
    cout << endl << 0 << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(3);

    int t;
    cin >> t;
    while(t--) 
        solve();
}