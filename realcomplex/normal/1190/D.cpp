#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const int N = (int)4e5 + 9;
 
ll tree[N * 4];
 
int m;
 
ll cnt[N * 4];
 
void upd(int nd, int x){
    nd += m;
    while(nd > 0){
        tree[nd] += x;
        nd /= 2;
    }
}
 
void add(int x){
    if(cnt[x] == 0)
        upd(x, +1);
    cnt[x] ++ ;
}
 
void rem(int x){
    if(cnt[x] == 1)
        upd(x, -1);
    cnt[x] -- ;
}
 
 
 
ll ask(int l, int r){
    l += m;
    r += m;
    ll answ = 0;
    while(l <= r){
        if(l % 2 == 1) answ += tree[l ++ ];
        if(r % 2 == 0) answ += tree[r -- ];
        l /= 2;
        r /= 2;
    }
    return answ;
}
 
ll f(ll x){
    return x * 1ll * (x + 1) / 2ll;
}
 
int main(){
    fastIO;
    int n;
    cin >> n;
    ll x[n], y[n];
    vector<int> crs;
    for(ll i = 0 ; i< n; i ++ ){
        cin >> x[i] >> y[i];
        crs.push_back(x[i]);
        crs.push_back(y[i]);
    }
    sort(crs.begin(), crs.end());
    crs.resize(unique(crs.begin(), crs.end()) - crs.begin());
    m = crs.size();
    vector<ll> spl;
    vector<pii> pp;
    for(int i = 0 ; i < n; i ++ ){
        x[i] = lower_bound(crs.begin(), crs.end(), x[i]) - crs.begin();
        y[i] = lower_bound(crs.begin(), crs.end(), y[i]) - crs.begin();
        spl.push_back(y[i]);
        pp.push_back(mp(y[i], x[i]));
    }
    sort(spl.begin(), spl.end());
    spl.resize(unique(spl.begin(), spl.end()) - spl.begin());
    sort(pp.begin(), pp.end());
    ll p = 0;
    for(int i = 0 ; i < pp.size(); i ++ )
        add(pp[i].se);
    ll total = 0;
    int t;
    for(int i = 0 ;i < spl.size(); i ++ ){
        vector<ll> cors;
        total += f(ask(0, m - 1));
        while(p < pp.size()){
            if(pp[p].fi > spl[i]) break;
            rem(pp[p].se);
            cors.push_back(pp[p].se);
            p ++ ;
        }
        sort(cors.begin(), cors.end());
        t = -1;
        for(auto p : cors){
            total -= f(ask(t + 1, p - 1));
            t = p;
        }
        total -= f(ask(t + 1, m - 1));
    }
    cout << total;
    return 0;
}