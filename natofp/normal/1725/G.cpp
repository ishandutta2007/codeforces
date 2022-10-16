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



void solve(){
    ll n; cin >> n;
    vector<ll> good;
    good = {3,5,7,8,9};
    if(n <= 5){
        cout << good[n - 1] << "\n";
        return;
    }
    n -= 5;
    ll bas = 11;
    n--;
    ll ful = (n / 3);
    bas += ful * 4;
    n -= ful * 3;
    while(n > 0){
        n--;
        bas++;
    }
    cout << bas << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}