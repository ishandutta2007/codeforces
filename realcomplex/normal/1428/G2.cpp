#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6;
ll F[6];
ll dp[N];
ll ndp[N];


int main(){
    fastIO;
    int k;
    cin >> k;
    for(int i = 0 ; i <= 5; i ++ ){
        cin >> F[i];
    }
    for(int i = 1; i < N ; i ++ ){
        dp[i] = -(ll)1e18;
    }
    ll mlt = 1;
    ll big;
    ll cum;
    ll pak;
    ll qq;
    for(int d = 0; d <= 5; d ++ ){
        big = (k-1) * 3ll;
        cum = 0;
        pak = 1ll;
        vector<ll> lis;
        while(cum + pak <= big){
            cum += pak;
            lis.push_back(pak);
            pak *= 2ll;
        }
        for(int j = 0 ; j < N; j ++ ){
            ndp[j] = -(ll)1e18;
        }
        if(big - cum > 0){
            qq = big - cum;
            for(int j = N - 1; j >= 0; j -- ){
                if(j + mlt * 3ll * qq < N){
                    ndp[j + mlt * 3ll * qq] = dp[j] + qq * 1ll * F[d];
                }
            }
        }
        for(auto x : lis){
            for(int j = N - 1; j >= 0 ; j -- ){
                if(j + x * 3ll * mlt < N){
                    dp[j + x * 3ll * mlt] = max(dp[j + x * 3ll * mlt], dp[j] + x * 1ll * F[d]);
                    ndp[j + x * 3ll * mlt] = max(ndp[j + x * 3ll * mlt], ndp[j] + x * 1ll * F[d]);
                }
            }
        }
        for(int j = 0 ; j < N ; j ++ ){
            dp[j] = max(dp[j], ndp[j]);
        }
        mlt *= 10ll;
    }
    mlt = 1;
    ll cost;
    for(int d = 0; d <= 5; d ++ ){
        for(int i = N - 1; i >= 0 ; i -- ){
            for(int dig = 1; dig < 10; dig ++ ){
                if(i + dig * 1ll * mlt < N){
                    cost = dp[i];
                    if(dig % 3 == 0) cost += F[d] * 1ll * (dig / 3);
                    dp[i + dig * 1ll * mlt] = max(dp[i + dig * 1ll * mlt], cost);
                }
            }
        }
        mlt *= 10ll;
    }
    int q;
    cin >> q;
    int x;
    for(int i = 1; i <= q; i ++ ){
        cin >> x;
        cout << dp[x] << "\n";
    }
    return 0;
}