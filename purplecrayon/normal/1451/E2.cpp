#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

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

int qA(int i, int j){
    cout << "AND " << (i+1) << ' ' << (j+1) << '\n'; cout.flush();
    int x; cin >> x; if (x == -1) exit(0);
    return x;
}
int qX(int i, int j){
    cout << "XOR " << (i+1) << ' ' << (j+1) << '\n'; cout.flush();
    int x; cin >> x; if (x == -1) exit(0);
    return x;
}
int qO(int i, int j){
    cout << "OR " << (i+1) << ' ' << (j+1) << '\n'; cout.flush();
    int x; cin >> x; if (x == -1) exit(0);
    return x;
}
void pr(vector<int> ans){
    cout << "! ";
    for (auto it : ans) cout << it << ' ';
    cout << '\n';
    exit(0);
}
void solve(){
    int n; cin >> n;
    vector<int> x(n);
    vector<int> c(n, -1);
    for (int i = 1; i < n; i++) x[i] = qX(0, i);
    vector<int> ans(n);
    for (int i = 1; i < n; i++){
        int v=-1;
        if (!x[i]) v = qA(0, i);
        if (c[x[i]] != -1) v = qA(c[x[i]], i)^x[i];
        if (v != -1){
            ans[0] = v;
            for (int j = 1; j < n; j++) ans[j] = ans[0]^x[j];
            pr(ans);
        }
        c[x[i]] = i;
    }
    int i1=-1, i2=-1;
    for (int i = 1; i < n; i++){
        if (x[i] == 1) i1 = i;
        else if (x[i] == 2) i2 = i;
    }
    assert(i1 != -1 && i2 != -1);
    int v = qA(0, i1)|(qA(0, i2)&1);
    ans[0] = v;
    for (int j = 1; j < n; j++) ans[j] = ans[0]^x[j];
    pr(ans);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}