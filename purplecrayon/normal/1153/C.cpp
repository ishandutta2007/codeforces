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
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n; string s; cin >> s;
    int tot=0, ps=0;
    for (auto c : s){
        if (c == '?') tot++;
        else if (c == '(') ps++;
        else if (c == ')') ps--;
        else assert(false);
    }
    //a+b = tot
    //a-b = -ps
    //a = (tot-ps)/2
    //b = tot-a 
    int a = (tot-ps)/2;
    int b = tot-a;
    bool bad = !(a >= 0 && b >= 0 && a+b == tot && a-b+ps == 0);
    // cout << tot << ' ' << ps << ' ' << a << ' ' << b << '\n';
    for (auto& c : s) if (c == '?') {
        if (a) c='(', --a;
        else c=')', --b;
    }
    ps=0; int cnt=0;
    if (!bad) for (auto& c : s){
        if (c == '(') ps++;
        else if (c == ')') ps--;
        else assert(false);
        cnt += !ps; bad |= ps < 0;
    }
    bad |= bool(ps); bad |= cnt > 1;
    // cout << s << '\n';
    if (bad) cout << ":(\n";
    else cout << s << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}