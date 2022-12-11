#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll L = (1ll << 31);

ll gen(){
    return ((ll)rng() % L + L) % L;
}

vector<ll> arr(int n){
    vector<ll> z(n);
    set<ll> meow;
    for(int i = 0 ; i < n; i ++ ){
        z[i] = gen();
        while(meow.count(z[i])) z[i]=gen();
        meow.insert(z[i]);
    }
    return z;
}

void solve(){
    int n;
    cin >> n;
    bool fin = false;
    vector<ll> q = arr(n);
    while(!fin){
        vector<ll> q = arr(n);
        ll pi = 0, qi = 0;
        for(int i = 0 ; i < n; i ++ ){
            if((i&1)) pi ^= q[i];
            else qi ^= q[i];
        }
        q[0] ^= (pi ^ qi);
        set<ll> uni;
        for(int i = 0 ; i < n; i ++ ){
            uni.insert(q[i]);
        }
        if(uni.size() == n){
            for(auto x : q) cout << x << " ";
            cout << "\n";
            fin=true;
            return;
        }
    }

}
int main(){
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;

}