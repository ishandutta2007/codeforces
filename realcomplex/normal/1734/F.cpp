#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 62;
const ll maxi = (ll)2e18;
ll dp[N][2][2][2]; // [bit][carry][smaller condition][parity_diff]


void add(ll &x, ll y){
    x += y;
    x = min(x, maxi); // for debugging purposes
}

void solve(){
    ll n, m;
    cin >> n >> m;
    // count between < m
    // such that f(i) != f(i + n)
    for(int i = 0 ; i < N; i ++ ){
        for(int p = 0 ; p < 2; p ++ ){
            for(int q = 0; q < 2; q ++ ){
                for(int z = 0; z < 2; z ++ ){
                    dp[i][p][q][z] = 0ll;
                }
            }
        }
    }
    dp[0][0][0][0] = 1;
    int nb;
    int mb;
    int added;
    int nsmall;
    for(int bit = 0; bit + 1 < N; bit ++ ){
        if((n & (1ll << bit))){
            nb = 1;
        }
        else{
            nb = 0;
        }
        if((m & (1ll << bit))){
            mb = 1;
        }
        else{
            mb = 0;
        }
        // f(i) != f(i + n)
        for(int carry = 0; carry < 2; carry ++ ){
            for(int smaller = 0; smaller < 2; smaller ++ ){
                for(int diff = 0; diff < 2; diff ++ ){
                    if(dp[bit][carry][smaller][diff] != 0){
                        for(int nex = 0; nex < 2; nex ++ ){
                            added = (carry + nex + nb);
                            nsmall = smaller;
                            if(nex != mb){
                                if(nex == 1) nsmall = 0;
                                else nsmall = 1;
                            }
                            add(dp[bit + 1][(added >= 2)][nsmall][(diff ^ ((added & 1) ^ nex))], dp[bit][carry][smaller][diff]);
                        }
                    }
                }
            }
        }
    }
    cout << dp[N - 1][0][1][1] << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}