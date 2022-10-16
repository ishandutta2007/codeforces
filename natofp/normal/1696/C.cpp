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
#define mt make_tuple

using namespace std;

int n, m, k;
vector<ll> a, b;

vector<pll> getRepr(vector<ll> a){
    vector<pll> res;
    for(ll cur : a){
        ll ile = 1;
        ll value = cur;
        while(value % m == 0){
            value /= m;
            ile *= m;
        }
        if(res.size() && res.back().st == value){
            res.back().nd += ile;
        }
        else res.pb(mp(value, ile));
    }
    return res;
}

void solve(){
    a.clear(); b.clear();
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int x; cin >> x; a.pb(x);
    }
    cin >> k;
    for(int i=1;i<=k;i++){
        int x; cin >> x; b.pb(x);
    }
    auto s1 = getRepr(a);
    auto s2 = getRepr(b);
    if(s1 == s2) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}