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

int n, m;
const int nax = 1e5 + 5;
vector<pii> s[nax];

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x; cin >> x; s[x].pb(mp(i, j));
        }
    }
    ll ans = 0;
    for(int i=1;i<nax;i++){
        vector<ll> s1, s2;
        for(pii cur : s[i]){
            s1.pb(cur.st);
            s2.pb(cur.nd);
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        ll p = 0;
        for(int i=0;i<s1.size();i++){
            ans += (s1[i] * i) - p;
            p += s1[i];
        }
        p = 0;
        for(int i=0;i<s2.size();i++){
            ans += (s2[i] * i) - p;
            p += s2[i];
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}