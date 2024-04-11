#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int mod = 998244353;
const int nax = 4444;

int binom[nax][nax];

void prep(){
    binom[0][0] = 1;
    for(int i=1;i<nax;i++){
        binom[i][0] = 1;
        for(int j=1;j<nax;j++){
            binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
            if(binom[i][j] >= mod) binom[i][j] -= mod;
        }
    }
}

int n, m;

int nk(int n, int k){
    if(k > n || k < 0 || n < 0) return 0;
    return binom[n][k];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    cin >> n >> m;
    ll ans = 0;
    for(int h=1;h<n;h++){
        int top = n - h;
        if(top <= 0) continue;
        int bot = h;
        vector<ll> sumka;
        ll sum = 0;
        sumka.pb(0);
        for(int i=1;i<=m;i++){
            ll cur = nk(top + (i - 1), (i - 1));
            cur *= nk(top + (m - i) - 1, (m - i));
            cur %= mod;
            sumka.pb(cur);
            sum += cur;
            if(sum >= mod) sum -= mod;
        }
        for(int i=m;i>=1;i--){
            sum -= sumka.back();
            if(sum < 0) sum += mod;
            sumka.pop_back();
            ll cur = nk(bot + (m - i), (m - i));
            cur *= nk(bot + (i - 1) - 1, (i - 1));
            cur %= mod;
            ans += cur * sum;
            ans %= mod;
        }
    }
    // JEST DOBRZE , TRZEBA TERAZ TAKIE CO NACHODZA POLICZYC :)
    // zrobmy tak samo i potem * 2 na koncu :D

    for(int col=1;col<m;col++){
        ll sum = 0;
        for(int h=2;h<n;h++){
            int top = h - 2;
            int bot = n - h + 1;
            ll cur = nk(top + (m - col), m - col);
            cur *= nk(bot + (m - col - 1), m - col - 1);
            cur %= mod;
            sum += cur;
            sum %= mod;

            ll akt = nk(h + col - 1, col - 1);
            int bot_opt = n - h - 1;
            akt *= nk(bot_opt + col, col);
            akt %= mod;
            ans += akt * sum;
            ans %= mod;
        }
    }

    cout << (ans * 2) % mod << "\n";


    return 0;
}