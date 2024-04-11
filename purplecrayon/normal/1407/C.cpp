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
 
map<pair<int, int>, int> mp;
int qry(int l, int r){
    ++l, ++r;

    if (mp.count(make_pair(l, r))) return mp[make_pair(l, r)];

    cout << "? " << l << ' ' << r << endl;
    int x; cin >> x;
    return mp[make_pair(l, r)] = x;
}
int n;
void solve(){
    cin >> n;
    int mx=0;
    vector<int> ans(n);
    for (int i = 1; i < n; i++){
        int v1=qry(i, mx), v2=qry(mx, i);
        if (v1 < v2) ans[mx]=v2, mx=i;
        else ans[i]=v1;
    }
    ans[mx] = n;
    
    cout << "! "; for (auto& it : ans) cout << it << ' ';
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}