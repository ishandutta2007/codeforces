#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef print
#define print(...)
#define trace(...)
// #define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
//const int mod = 998244353;
const int mod = 1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

int n;
int ans;
int ar[10000];
int si[10000];

int ask(int i, int j, int k, int q=2) {
    cout << q << " " << i << " " << j << " " << k << endl;
    cin >> ans;
    return ans;    
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    cin >> n;
    int f = 1, s = 2;
    vector<pair<int,int>> ne, po;
    for (int i = 3; i <= n; i++) {
        ar[i] = ask(f, s, i, 1);
        si[i] = ask(f, s, i);
        if (si[i] == -1) {
            ne.pb({ar[i], i});
        } else {
            po.pb({ar[i], i});
        }
    }
    vi re = {f};
    if (!ne.empty()) {
        sort(all(ne));
        reverse(all(ne));
        vi a1 = {ne[0].se}, a2 = {};
        int se = ne[0].se;
        for (int i = 1; i < ne.size(); i++) {
            if (ask(f, se, ne[i].se) == -1) {
                a1.pb(ne[i].se);
            } else {
                a2.pb(ne[i].se);
            }
        }
        reverse(all(a1));
        for (int i = 0; i < a1.size(); i++) {
            re.pb(a1[i]);
        }
        for (int i = 0; i < a2.size(); i++) {
            re.pb(a2[i]);
        }
    }
    re.pb(s);
    if (!po.empty()) {
        sort(all(po));
        reverse(all(po));
        vi a1 = {po[0].se}, a2 = {};
        int se = po[0].se;
        for (int i = 1; i < po.size(); i++) {
            if (ask(f, se, po[i].se) == -1) {
                a1.pb(po[i].se);
            } else {
                a2.pb(po[i].se);
            }
        }
        reverse(all(a1));
        for (int i = 0; i < a1.size(); i++) {
            re.pb(a1[i]);
        }
        for (int i = 0; i < a2.size(); i++) {
            re.pb(a2[i]);
        }
    }
    cout << 0 << " ";
    for (int i = 0; i < re.size(); ++i) {
        cout << re[i] << " ";
    }
    cout << endl;
}