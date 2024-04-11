#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 4e5 + 5;
int mine[nax], his[nax];
int n, m, q;
ll ans[nax];
ll pref[nax * 2];

ll ask(int lo, int hi){
    ll res = pref[hi];
    if(lo) res -= pref[lo - 1];
    return res;
}

int par[nax];
int sz[nax];
int ile[nax];
int L[nax], R[nax];
ll wynik[nax];
void ini(){
    for(int i=0;i<nax;i++){
        sz[i] = 1;
        par[i] = i;
        L[i] = R[i] = i;
        ile[i] = 0;
    }
}

int f(int x){
    if(par[x] == x) return x;
    return par[x] = f(par[x]);
}

ll answer = 0;

void u(int x, int y){
    x = f(x);
    y = f(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x, y);
    answer -= wynik[x];
    answer -= wynik[y];
    sz[y] += sz[x];
    par[x] = y;
    ile[y] += ile[x];
    R[y] = max(R[y], R[x]);
    L[y] = min(L[y], L[x]);
    int lo = L[y];
    int hi = R[y];
    int c = ile[y];
    ll s = ask(hi - c + 1, hi);
    wynik[y] = s;
    answer += s;
}

void solve(){
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++) cin >> mine[i];
    for(int i=1;i<=m;i++) cin >> his[i];
    vector<ll> a;
    for(int i=1;i<=n;i++) a.pb(mine[i]);
    for(int i=1;i<=m;i++) a.pb(his[i]);
    vector<pii> Q;
    for(int i=1;i<=q;i++){
        int k; cin >> k;
        Q.pb(mp(k, i));
    }
    sort(Q.begin(), Q.end());
    sort(a.begin(), a.end());
    pref[0] = a[0];
    for(int i=1;i<a.size();i++) pref[i] = pref[i - 1] + a[i];
    multiset<int> mam;
    for(int i=1;i<=n;i++) mam.insert(mine[i]);
    int all = n + m;
    ini();
    for(int i=0;i<all;i++){
        int v = a[i];
        if(mam.count(v)){
            mam.erase(mam.find(v));
            ile[i] = 1;
            answer += v;
            wynik[i] = v;
        }
    }
    vector<pair<ll, pii> > difs;
    for(int i=0;i<all-1;i++){
        ll v = abs(a[i] - a[i + 1]);
        difs.pb(mp(v, mp(i, i + 1)));
    }
    sort(difs.begin(), difs.end());
    int wsk = 0;
    for(auto zap : Q){
        ll k = zap.st;
        int id = zap.nd;
        while(wsk < difs.size() && difs[wsk].st <= k){
            int x1 = difs[wsk].nd.st;
            int x2 = difs[wsk].nd.nd;
            u(x1, x2);
            wsk += 1;
        }
        ans[id] = answer;
    }
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}