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


void solve(){
    ll c, d; cin >> c >> d;
    if(abs(c + d) % 2 == 1){
        cout << -1 << "\n";
        return;
    }
    if(c == 0 && d == 0) cout << 0 << "\n";
    else if(abs(c) == abs(d)) cout << 1 << "\n";
    else cout << 2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}