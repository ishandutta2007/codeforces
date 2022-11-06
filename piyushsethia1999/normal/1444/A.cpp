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
#define endl '\n'
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

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t; cin >> t;
    while (t--) {
        int p; cin >> p;
        int q; cin >> q;
        if (p % q != 0) {
            cout << p << '\n';
            continue;
        }
        int ma = 1;
        for (int i = 2; i * i <= q; ++i) {
            if (q % i == 0) {
                int cnt = 0;
                while (q % i == 0) {
                    q /= i;
                    cnt++;
                }
                int pp = p;
                while (pp % i == 0) {
                    pp /= i;
                }
                for (int j = 0; j < cnt - 1; ++j) {
                    pp *= i;
                }
                ma = max(ma, pp);
            } 
        }
        if (q != 1) {
            int i = q, cnt = 1;
            int pp = p;
            while (pp % i == 0) {
                pp /= i;
            }
            for (int j = 0; j < cnt - 1; ++j) {
                pp *= i;
            }
            ma = max(ma, pp);    
        } 
        cout << ma << '\n';
    }
}