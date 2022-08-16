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
const int MAXN = 5e5+10, MAXM = 5e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 110, INF = 1e9+10, MAXA = 62, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int p[MAXM], sz[MAXM];
ll ans[MAXM];

int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
ll po(ll b, ll p){
    ll r=1;
    for (; p; b=b*b%MOD, p/=2) if (p&1) r=r*b%MOD;
    return r;
}

void solve(){
    int n, m; cin >> n >> m; iota(p, p+m+1, 0);

    vector<int> s_p;
    for (int i = 0; i < n; i++){
        int c; cin >> c;
        if (c == 1){
            int a; cin >> a, --a; a = find_set(a);
            if (a != find_set(m)){
                p[a] = find_set(m); s_p.push_back(i);
            }
        } else {
            int a, b; cin >> a >> b, --a, --b;
            a=find_set(a), b=find_set(b);
            if (a != b){
                p[a] = b; s_p.push_back(i);
            }
        }
    }
    cout << po(2, sz(s_p)) << ' ' << sz(s_p) << '\n';
    for (auto& it : s_p) cout << (it+1) << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}