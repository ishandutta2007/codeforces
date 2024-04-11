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

const int nax = 1e6 + 5;
int a[nax];
int b[nax];
const int mod = 998244353;
ll n, m;

ll f[nax];
ll iw[nax];

ll pp(ll a, ll b){
    ll cur = a;
    ll res = 1;
    for(int i=0;i<60;i++){
        if(b & (1LL << i)){
            res *= cur;
            res %= mod;
        }
        cur *= cur;
        cur %= mod;
    }
    return res;
}

void prep(){
    f[0] = 1;
    iw[0] = 1;
    for(int i=1;i<nax;i++){
        f[i] = f[i - 1] * i;
        f[i] %= mod;
        iw[i] = pp(f[i], mod - 2);
    }
}

ll nk(ll n, ll k){
    ll res = f[n];
    res *= iw[k];
    res %= mod;
    res *= iw[n - k];
    res %= mod;
    return res;
}


void solve(){
    cin >> n;
    ll ans = 0;
    // TAKIE PLANSZE CO MAJA NOT MONO KOLUMNY -> ILE Z NICH MA WSZYSTKIE WIERSZE TEZ NOT MONO
    ll opt = pp(3, n) - 3;
    if(opt < 0) opt += mod;
    ans = pp(opt, n);
    for(int monocolorRows=1;monocolorRows<=n;monocolorRows++){
        // all columns NOT MONO !!
        // exactly this set of rows is  MONO

        ll waysToChose = nk(n, monocolorRows);
        ll combiNotAllTheSame = pp(3, monocolorRows) - 3;
        if(combiNotAllTheSame < 0) combiNotAllTheSame += mod;

        ll combiAllTheSame = 3;
        ll total = (combiNotAllTheSame) * pp(3, n * (n - monocolorRows));

        ll total2 = (combiAllTheSame);
        ll goodOptForCol = pp(3, n - monocolorRows) - 1;
        if(goodOptForCol < 0) goodOptForCol += mod;

        total2 *= pp(goodOptForCol, n);
        total2 %= mod;

        total += total2;
        total %= mod;
        total *= waysToChose;
        total %= mod;
        if(monocolorRows % 2 == 0) ans += total;
        else ans -= total;
        if(ans < 0) ans += mod;
        if(ans >= mod) ans -= mod;
    }
    ll ful = pp(3, n * n);
    ful -= ans;
    if(ful < 0) ful += mod;
    cout << ful << "\n";



}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}