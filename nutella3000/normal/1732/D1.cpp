#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e15;

void run() {
    int q; cin >> q;
    map<ll, vector<ll>> mex;
    map<ll, set<ll>> pot;
    map<ll, ll> mex_nxt;
    set<ll> xs;

    while (q--) {
        char c;
        ll x; cin >> c >> x;

        if (c == '+') {
            xs.insert(x);
        } else if (c == '-') {
            for (auto i : mex[x]) {
                pot[i].insert(x);
            }
            mex.erase(x);
            xs.erase(x);
        } else {
            bool find = false;
            for (auto it = pot[x].begin(); it != pot[x].end();) {
                if (!xs.count(*it)) {
                    cout << *it << '\n';
                    find = true;
                    break;
                }
                mex[*it].push_back(x);
                it = pot[x].erase(it);
            }
            if (!find) {
                auto& it = mex_nxt[x];
                if (it == 0) it = x;

                while (xs.count(it)) {
                    mex[it].push_back(x);
                    it += x;
                }
                cout << it << '\n';
            }
        }
    }
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        run();
    }
}