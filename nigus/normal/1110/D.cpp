#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,q;
const ll big = 1000000007;
const ll big2 = 998244353;

const int MAXN = 1000000;
const int lim = 8;

int F[MAXN+10] = {0};

int DP[2][lim+1][lim+1] = {0};
/*
int dp(ll i, ll f1, ll f2){
    if(i == m)return 0;
    if(DPC[i][f1][f2])return DP[i][f1][f2];
    int ans = dp(i+1,f2,F[i+2]);
    if(f1 >= 3){
        ans = max(ans, 1+dp(i,f1-3,f2));
    }
    if(m-i > 2){
        int f3 = F[i+2];
        if(f1 > 0 && f2 > 0 && f3 > 0){
            ans = max(ans, 1 + dp(i+1,f2-1,f3-1));
        }
        if(f1 > 1 && f2 > 1 && f3 > 1){
            ans = max(ans, 2 + dp(i+1,f2-2,f3-2));
        }
    }
    DPC[i][f1][f2] = 1;
    DP[i][f1][f2] = ans;
    return ans;
}
*/
ll ans2 = 0;
void dp(){

    for(int i = m; i >= 0; i--){
        for(int f1 = 0; f1 <= lim; f1++){
            for(int f2 = 0; f2 <= lim; f2++){

                if(i == m){
                    DP[0][f1][f2] = 0;
                    continue;
                }

                int f3 = F[i+2];

                int ans = DP[1][f2][f3];
                if(f1 >= 3){
                    ans = max(ans, 1+DP[0][f1-3][f2]);
                }
                if(m-i > 2){
                    if(f1 > 0 && f2 > 0 && f3 > 0){
                        ans = max(ans, 1 + DP[1][f2-1][f3-1]);
                    }
                    if(f1 > 1 && f2 > 1 && f3 > 1){
                        ans = max(ans, 2 + DP[1][f2-2][f3-2]);
                    }
                }
                DP[0][f1][f2] = ans;
                if(i == 0 && f1 == F[0] && f2 == F[1]){ans2 = ans;}
            }
        }
        for(int f1 = 0; f1 <= lim; f1++){
            for(int f2 = 0; f2 <= lim; f2++){
                DP[1][f1][f2] = DP[0][f1][f2];
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> m;
   // n = 1e6;
   // m = 1e6;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
       // a = (rand()*rand() % m)+1;
        F[a-1]++;
    }
    F[m] = 0;
    F[m+1] = 0;
    ll ans = 0;
    for(int c1 = 0; c1 < m; c1++){
        while(F[c1] > lim){
            F[c1] -= 3;
            ans++;
        }
    }
    dp();
    cout << ans2+ans << "\n";


    return 0;
}