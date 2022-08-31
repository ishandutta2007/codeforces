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
const int VAL = 1000;

map<int, pair<int, int>> mp;
pair<int, int> qry(int c) {
    if (mp.count(c)) return mp[c];
    cout << "? " << c << endl;
    int val, nxt; cin >> val >> nxt;
    return mp[c] = {val, nxt};
}
void solve(){
    int n, start, x; cin >> n >> start >> x;
    int c = start;
    for (int rep = 0; rep < VAL; rep++) {
        int i = rnd(1, n);
        int val = qry(i).first;
        if (val < x && val >= qry(c).first) c = i;
    }
    while (qry(c).first < x) {
        c = qry(c).second;
        if (c == -1){ cout << "! -1" << endl; return; }
    }
    cout << "! " << qry(c).first << endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}