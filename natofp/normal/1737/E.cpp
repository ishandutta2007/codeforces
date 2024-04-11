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

const int mod = 1e9 + 7;

ll pp(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return res;
}

const int nax = 1e6 + 5;
ll prob[nax];
int n;
ll pw[nax];
ll suf[nax];

void add(ll &a, ll b){
    a += b;
    a %= mod;
}

void solve(){
    cin >> n;
    pw[0] = 1;
    for(int i=1;i<=n;i++){
        pw[i] = pw[i - 1] * 2;
        pw[i] %= mod;
    }
    prob[n] = pw[0];
    suf[n] = prob[n];
    suf[n + 1] = 0;
    for(int i=n-1;i>=1;i--){
        int go_mx = i + i - 1;
        ll all = suf[i + 1] * pp(pw[n - i], mod - 2);
        all %= mod;
        if(go_mx < n){
            ll zle = suf[go_mx + 1] * pp(pw[n - i], mod - 2);
            zle %= mod;
            all -= zle;
            if(all < 0) all += mod;
        }

        ll coef = all;
        if(coef < 0) add(coef, mod);
        coef %= mod;
        prob[i] = 0;
        add(prob[i], coef);
        int rst = n - i;
        if(i > rst){
            add(prob[i], pp(pw[rst], mod - 2));
        }
        suf[i] = suf[i + 1] + (prob[i] * pw[n - i]) % mod;
        suf[i] %= mod;
    }

    for(int i=1;i<=n;i++){
        ll need = (i + 1) / 2;
        if(i == n) need = (n - 1) / 2;
        if(i == 1) need = 0;
        ll szansa = pp(pw[need], mod - 2);
        szansa *= prob[i];
        szansa %= mod;
        cout << szansa << "\n";
    }


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}