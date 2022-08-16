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
const int MAXN = 2e5+10, MAXQ = 5e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 110, INF = 1e9+10, MAXA = 62, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


int n, m;
char a[MAXN];
int rl[MAXN], rr[MAXN], ret[MAXN];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    cin >> n >> m;

    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) { int c; cin >> c; a[c]^=1; }

    int q; cin >> q;
    for (int i = 0; i < q; i++) cin >> rl[i] >> rr[i];

    for (int i = 0; i < q; i++) {
        int l=rl[i], r=rr[i];

        int ans=0;
        for (int i = l; i <= r; i++) ans ^= a[i]*(i-l);
        ret[i] = ans;
    }
    for (int i = 0; i < q; i++) 
        cout << char((bool(ret[i])^1)+'A');
}