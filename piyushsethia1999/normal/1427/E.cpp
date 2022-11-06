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

long long bitt[64];
std::vector<int> fii;
std::vector<int> see;
std::vector<string> op;
int add(int a) {
    int A = a;
    for (int i = 62; i >= 0; --i) {
        if ((1ll << i) & a) {
            if (bitt[i] == 0) {
                // bitt[i] = a;
                return i;
            } else {
                a ^= bitt[i];
            }
        }
    }
    a = A;
    return -1;
}

int add1(int a) {
    for (int i = 62; i >= 0; --i) {
        if ((1ll << i) & a) {
            if (bitt[i] == 0) {
                bitt[i] = a;
                return i;
            } else {
                fii.pb(bitt[i]);
                see.pb(a);
                op.pb("^");
                a ^= bitt[i];
            }
        }
    }
    return -1;
}

void printfinal() {
    cout << fii.size() << "\n";
    for (int i = 0; i < fii.size(); ++i) {
        cout << fii[i] << " " << op[i] << " " << see[i] << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int x; cin >> x;
    // print(x << 6, (x * (1 << 6)));
    for (int i = 1; i < 64; ++i) {
        if ((x << i) <= 800000000000000ll) {
            fii.pb(x << (i - 1));
            op.pb("+");
            see.pb(x << (i - 1));
            // print(i);
        } else {
            break;
        }
    }
    fii.pb(x);
    see.pb(x);
    op.pb("^");
    for (int i = 1; i <= 40000000; ++i) {
        if (add(i * x) != -1) {
            int res = 0;
            for (int j = 0; j < 50; ++j) {
                if (i & (1ll << j)) {
                    fii.pb(x * (1ll << j));
                    see.pb(res);
                    op.pb("+");
                    res += (x * (1ll << j));
                }
            }
            if(add1(i * x) == 0) {
                printfinal();
                return 0;
            }
        }
    }
    // }
    // print(ma);
}