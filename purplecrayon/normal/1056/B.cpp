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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<ll> cnt(m);
    for (int i = 0; i < m; i++) cnt[i] = n/m;
    for (int i = 1; i <= n%m; i++) cnt[i%m]++;
    ll ans=0;
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) if ((i*i+j*j)%m == 0) ans += cnt[i]*cnt[j];
    cout << ans << '\n';
}