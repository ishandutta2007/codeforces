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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    //need to find some ordering such that most adj numbers are not coprime
    //n can connect to anything
    //consider each of the distinct prime factors
    //each of those cannot be next to eachother
    //and they must always be next to a multiple of themselves
    //if a prime has a power of 1
    //if it is a power of a prime -> always works
    //otherwise use all primes and semiprimes, easily work (non circular array)
    //count the number of primes who have <= 1 other things that work
    //first insert primes everywhere
    //the main issue is prime powers
    //first insert all of the primes (and prime powers)
    //then insert all of the semiprimes between them
    //then i can insert everything else smwhere (and it doesn't matter)
    //
    //if n is a semiprime -> bad
    //otherwise has 
    
    ll n; cin >> n;
    vector<ll> d;
    for (ll i=2; i*i <= n; i++) if (n%i == 0){
        d.push_back(i);
        if (i*i != n) d.push_back(n/i);
    }
    d.push_back(n);
    ll nn=n;
    vector<pair<ll, int>> pf;
    for (ll i=2; i*i <= nn; i++) if (nn%i == 0){
        pf.emplace_back(i, 0);
        while (nn%i == 0) pf.back().second++, nn /= i;
    }
    if (nn > 1) pf.emplace_back(nn, 1);
    if (sz(pf) == 1) {
        for (auto& it : d) cout << it << ' ';
        cout << '\n' << 0 << '\n';
        return;
    }
    set<ll> spec;
    if (sz(pf) == 2){
        if (pf[0].second == 1 && pf[1].second == 1){
            cout << pf[0].first << ' ' << pf[1].first << ' ' << n << '\n';
            cout << 1 << '\n';
        } else {
            if (pf[0].second < pf[1].second) swap(pf[0], pf[1]);
            ll p=pf[0].first;
            for (int i = 0; i < pf[0].second; i++, p *= pf[0].first) cout << p << ' ';
            cout << pf[0].first*pf[1].first << ' ';
            p=pf[1].first;
            for (int i = 0; i < pf[1].second; i++, p *= pf[1].first) cout << p << ' ';
            ll p1=1;
            for (int i = 1; i <= pf[0].second; i++) {
                p1*=pf[0].first; ll p2=1;
                for (int j = 1; j <= pf[1].second; j++) if (i>1||j>1){
                    p2 *= pf[1].first;
                    cout << p1*p2 << ' ';
                }
            }
            cout << '\n';
            cout << 0 << '\n';                
        }
        return;
    }
    vector<ll> sp;
    for (int i = 0; i < sz(pf); i++){
        ll c=pf[i].first*pf[(i+1)%(sz(pf))].first;
        sp.push_back(c);
        spec.insert(c);
    }
    vector<vector<ll>> g(sz(pf));
    for (int i = 0; i < sz(d); i++) if (!spec.count(d[i])) {
        for (int j = 0; j < sz(pf); j++) if (d[i]%pf[j].first == 0){
            g[j].push_back(d[i]);
            break;
        }
    }
    for (int i = 0; i < sz(pf); i++){
        for (auto& it : g[i]) cout << it << ' ';
        cout << sp[i] << ' ';
    }
    cout << '\n' << 0 << '\n';
        
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}