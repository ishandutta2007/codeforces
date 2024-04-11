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

vector<vector<ll> > a;
int n, m;

ll ciezkosc(vector<ll> cur){
    ll ans = 0;
    for(int i=0;i<cur.size();i++){
        ans += (ll)cur[i] * i;
    }
    return ans;
}

void solve(){
    cin >> n >> m;
    a.clear();
    for(int i=1;i<=n;i++){
        vector<ll> cur;
        for(int j=1;j<=m;j++){
            ll x; cin >> x;
            cur.pb(x);
        }
        a.pb(cur);
    }
    vector<ll> ciezk;
    for(int i=0;i<n;i++) ciezk.pb(ciezkosc(a[i]));
    int id = -1;
    for(int i=0;i<n;i++){
        int p1 = i - 1;
        int p2 = i + 1;
        if(p1 < 0) p1 += n;
        if(p2 >= n) p2 -= n;
        if(ciezk[i] != ciezk[p1] && ciezk[i] != ciezk[p2]) id = i;
    }
    cout << id + 1 << " ";
    int id2 = 0;
    if(id == 0) id2 = 1;
    cout << ciezk[id] - ciezk[id2] << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}