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
const int MAXN = (1<<18)+10, MAXQ = 3e5+10, MAXL = 31, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int n, p[MAXN], sz[MAXN], cnt[MAXN];
ll ans=0;
bool con[MAXN];

int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
void union_sets(int a, int b) {
    int pa=find_set(a), pb=find_set(b);
    if (pa == pb) return;

    if (con[a] && con[b]) ans += ll(a+b);
    else if (con[a] && !con[b]) ans += ll(a+b)*cnt[b];
    else if (con[b] && !con[a]) ans += ll(a+b)*cnt[a];
    else ans += ll(a+b)*(cnt[a]+cnt[b]-1);

    con[a] = 1, con[b] = 1;
    if (sz[pa] < sz[pb]) swap(pa, pb);
    p[pb] = pa, sz[pa] += sz[pb], sz[pb] = 0;
}
void solve(){
    cin >> n;

    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) { int a; cin >> a; cnt[a]++; ans -= a; }
    cnt[0]++;

    iota(p, p+MAXN, 0), fill(sz, sz+MAXN, 1), fill(con, con+MAXN, 0);

    for (int i = (1<<18)-1; i >= 0; i--) {
        for (int s=i; s; s=(s-1)&i) {
            int a=s, b=i^s;
            if (cnt[a] && cnt[b])
                union_sets(a, b);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}