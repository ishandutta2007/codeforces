#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

vector<ll> good;

void solve(){
    ll n; cin >> n;
    int ile = 0;
    for(int i=good.size()-1;i>=0;i--){
        while(n >= good[i]){
            n -= good[i];
            ile++;
        }
    }
    if(n > 0) cout << -1<<"\n";
    else cout<<ile<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    good.pb(2050);
    while(good.back() < 1e17){
        good.pb(good.back() * 10);
    }
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}