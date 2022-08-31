#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}
int n, a[MAXN];
int mark[MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    fill(mark, mark+n, 3);

    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        if (a[i]) st.insert({a[i], i});
        else {
            int x = sz(st);
            for (int j = 0; j < min(3, x); j++) {
                auto c = *st.rbegin(); st.erase(prev(st.end()));

                mark[c.second] = j;
            }
            st.clear();
        }
    }

    int sz = 0;
    string add[4]={"pushStack", "pushQueue", "pushFront", "pushBack"};
    string pop[4]={"popStack", "popQueue", "popFront", "popBack"};

    for (int i = 0; i < n; i++) {
        if (a[i]) cout << add[mark[i]] << '\n', sz++;
        else {
            cout << min(3, sz);
            for (int j = 0; j < min(3, sz); j++) {
                cout << ' ' << pop[j];
            }
            cout << '\n';
            sz = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}