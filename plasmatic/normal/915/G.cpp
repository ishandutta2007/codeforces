// ./g-coprime-arrays.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const ll MOD = 1e9 + 7;
ll madd(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }
ll msub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
ll mmul(ll a, ll b, ll mod = MOD) { return (a * b) % mod; }
ll fpow(ll x, ll y, ll mod = MOD) {
    if (!y) return 1LL;
    return mmul(fpow(mmul(x, x, mod), y >> 1, mod), (y & 1) ? x : 1LL, mod);
}
ll mdiv(ll x, ll y, ll mod = MOD) { return mmul(x, fpow(y, mod - 2, mod), mod); }

const int MN = 2e6 + 1;
int N, K,
    jmp[MN], pcnt[MN], ppcnt[MN];

ll cans = 0,
   cnt[MN], pn[MN];
bool isp[MN], use[MN];
vector<int> fct[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(isp + 2, isp + MN, true);
    for (auto i = 2; i < MN; i++) {
        if (isp[i]) {
            jmp[i] = 1;
            for (int j = i * 2; j < MN; j += i) {
                jmp[j] = j / i;
                isp[j] = false;
            }
        }
    }

    vector<int> cuse;
    cin >> (N) >> (K);
    for (auto i = 1; i <= K; i++) {
        pn[i] = fpow(i, N);

        int c = i;
        while (c > 1) {
            int p = c / jmp[c];
            if (!use[p]) {
                use[p] = true;
                cuse.pb(p);
            }
            ppcnt[i]++;
            c = jmp[c];
        }
        pcnt[i] = SZ(cuse);
        for (auto x : cuse) use[x] = false;
        cuse.clear();
        // cout<<"i="<<(i)<<", "; cout<<"pcnt[i]="<<(pcnt[i])<<", "; cout<<"ppcnt[i]="<<(ppcnt[i])<<", "; cout << endl; // db i,pcnt[i],ppcnt[i]
    }

    ll ans = 0;
    for (auto i = 1; i <= K; i++) {
        if (i > 1) {
            if (pcnt[i] == ppcnt[i])
                for (int j = i; j <= K; j += i)
                    fct[j].pb(i);


            // assert(cnt[p] + 1 < 2000001);
            for (int x : fct[i]) {
                ll delta = msub(pn[cnt[x] + 1], pn[cnt[x]]);
                if (pcnt[x] & 1)
                    cans = madd(cans, delta);
                else 
                    cans = msub(cans, delta);
                cnt[x]++;
            }
        }

        ans += msub(pn[i], cans) ^ i;
        // if (K<=1000) {
        //     cout<<"pn[i]="<<(pn[i])<<", "; cout<<"msub(pn[i],cans)="<<(msub(pn[i],cans))<<", "; cout << endl; // db pn[i],msub(pn[i],cans)
        //     cout<<"i="<<(i)<<", "; cout << "fct[i]=["; for (auto x:fct[i])cout<<x<<", "; cout<<"], "; cout<<"cans="<<(cans)<<", "; cout << endl; // db i,I:fct[i],cans
        // }
    }

    cout << (ans % MOD) << '\n';

    return 0;
}