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

const int nax = 14;
const int mod = 1e9 + 7;
int prob[nax][nax];
int a[nax];

ll pp(ll a, ll b){
    if(!b) return 1;
    ll ans = pp(a, b / 2);
    ans *= ans;
    ans %= mod;
    if(b & 1) ans *= a;
    ans %= mod;
    return ans;
}

int dominating[1 << nax];
int ex[1 << nax];
int scc[1 << nax];
int beatAll[nax][1 << nax];

void solve(){
    int n; cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            prob[i][j] = ((ll)a[i] * pp((a[i] + a[j]), mod - 2)) % mod;
        }
    }
    for(int i=0;i<(1<<n);i++){
        ll w = 1;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if((i & (1 << j)) && (!((1 << k) & i))){
                    w *= prob[j][k];
                    w %= mod;
                }
            }
        }
        dominating[i] = w;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++){
            if(j & (1 << i)) continue;
            ll w = 1;
            for(int k=0;k<n;k++){
                if(j & (1 << k)){
                    w *= prob[i][k];
                    w %= mod;
                }
            }
            beatAll[i][j] = w;
        }
    }


    for(int i=0;i<(1<<n);i++){
        scc[i] = 1;
        int s = i;
        while (s > 0) {
            if(s != i){
                ll bad = scc[s];
                int maskLose = (i ^ s);
                for(int k=0;k<n;k++){
                    if(s & (1 << k)){
                        bad *= beatAll[k][maskLose];
                        bad %= mod;
                    }
                }
                scc[i] -= bad;
            }
            if(scc[i] < 0) scc[i] += mod;
            s = (s-1) & i;
        }
        ex[i] = ((ll)dominating[i] * scc[i]) % mod;
    }
    ll ans = 0;
    for(int i=0;i<(1<<n);i++){
        ans += (ll)ex[i] * (__builtin_popcount(i));
        ans %= mod;
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