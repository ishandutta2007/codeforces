#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e3, MAXM = 1e5+10, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

int n, k, mx, idx, ans;
vector<int> sub[MAXN];

int qry(vector<int>& v){
    cout << "? " << sz(v) << " ";
    for (auto it : v) cout << it+1 << " ";
    cout << "\n"; cout.flush();
    int x; cin >> x;
    if (x == -1){ cout << "BAD QUERY\n"; exit(0); }
    return x;
}
int qry(int l, int r){
    vector<int> v;
    for (int i = l; i <= r; i++) v.insert(v.end(), sub[i].begin(), sub[i].end());
    return qry(v);
}
int qry2(int l, int r){
    vector<int> v(r-l+1); iota(v.begin(), v.end(), l);
    return qry(v);
}
int dfs(int l, int r){
    // cout << "DFS: " << l << " " << r << "\n";
    if (l == r) return l;
    int mid = (l+r)>>1;
    if (qry(l, mid) == mx) return dfs(l, mid);
    return dfs(mid+1, r);
}
void solve(){
    cin >> n >> k;
    for (int i = 0; i < k; i++){
        int c; cin >> c; sub[i].assign(c, 0); 
        for (int j = 0; j < c; j++) cin >> sub[i][j], --sub[i][j];
    }
    int l = 0, r = k-1; 
    mx = qry2(0, n-1); idx = dfs(l, r); //cout << "HERE: " << mx << " " << idx << "\n";
    vector<int> v; vector<bool> in(n, false); for (auto it : sub[idx]) in[it]=1;
    for (int i = 0; i < n; i++) if (!in[i]) v.push_back(i);//, cout << "I: " << i << "\n";
    ans = qry(v);
    cout << "! "; for (int i = 0; i < k; i++) cout << (i == idx ? ans : mx) << " ";
    cout << "\n"; cout.flush(); string s; cin >> s;
    if (s != "Correct") exit(0);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    cin >> t; 
    while (t--) solve();
}