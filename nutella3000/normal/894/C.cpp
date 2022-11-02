#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
 
const int inf = 1e17 + 7;

vector<int> res;

void f(set<int> a) {
    while(a.size()) {
        int num = *a.begin();
        res.emplace_back(num);
        set<int> b;
        vector<int> temp;
        for(int i : a) {
            if (i % num == 0) {
                if (i != num)
                    b.emplace(i);
                temp.emplace_back(i);
            }
        }
        for(int i : temp)
            a.erase(i);

        if (b.size())
            f(b);
    }
}

void solve() {
    int n, st;
    cin >> n >> st;

    set<int> a;
    bool bad = false;
    for(int i = 0;i < n - 1;i++) {
        int v;
        cin >> v;
        a.emplace(v);
        bad |= v % st != 0;
    }

    if (bad) {
        cout << -1;
        return;
    }

    res.emplace_back(st);
    for(int i : a) {
        res.emplace_back(i);
        res.emplace_back(st);
    }

    cout << res.size() << endl;
    for(int i : res)
        cout << i << " ";
} 

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}