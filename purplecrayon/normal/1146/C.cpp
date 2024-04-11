#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
 
int ans=0;
int qry(vector<int> a, vector<int> b){
    cout << sz(a) << ' ' << sz(b) << ' ';
    for (auto& v : a) cout << v+1 << ' ';
    for (auto& v : b) cout << v+1 << ' ';
    cout << endl;

    int x; cin >> x; while (x==-1);
    ans = max(ans, x);
    return x;
}
int n;

vector<int> concat(vector<int> a, vector<int> b){
    vector<int> r=a;
    for (auto x : b) r.push_back(x);
    return r;
}
void rec(vector<vector<int>> a){
    vector<vector<int>> a1(sz(a)), a2(sz(a));

    for (int j = 0; j < sz(a); j++) 
        for (int i = 0; i < sz(a[j]); i++) 
            if (i < sz(a[j])/2) a1[j].push_back(a[j][i]);
            else a2[j].push_back(a[j][i]);

    vector<int> h1, h2;
    for (auto& v : a1) h1 = concat(h1, v);
    for (auto& v : a2) h2 = concat(h2, v);
    qry(h1, h2);

    vector<vector<int>> nw;
    for (auto& v : a1) if (sz(v) > 1) nw.push_back(v);
    for (auto& v : a2) if (sz(v) > 1) nw.push_back(v);

    if (sz(nw))
        rec(nw);
}
void solve(){
    cin >> n; ans=0;
    vector<int> v(n); iota(v.begin(), v.end(), 0);

    rec({v});
    cout << -1 << ' ' << ans << endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}