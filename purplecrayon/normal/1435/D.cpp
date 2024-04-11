#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> v(2*n);
    set<int> s;
    for (int i = 0; i < 2*n; i++){
        char c; cin >> c; v[i].first = (c=='+');
        if (!v[i].first) cin >> v[i].second;
        else s.insert(i);
    }
    vector<int> a; a.reserve(n);
    for (int i = 0; i < 2*n; i++){
        if (!v[i].first) a.push_back(i);
    }
    sort(a.begin(), a.end(), [&](auto x, auto y) -> bool  {
        return v[x].second < v[y].second;
    });
    for (auto x : a){
        auto it = s.lower_bound(x); if (it == s.begin()){ cout << no; return; }
        --it;
        v[*it].second = v[x].second;
        s.erase(it);
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto it : v){
        if (it.first) q.push(it.second);
        else {
            int c = q.top(); q.pop();
            if (c != it.second){ cout << no; return; }
        }
    }
    cout << yes;
    for (auto it : v) if (it.first) cout << it.second << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}