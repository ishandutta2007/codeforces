#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,q,m,k;
ll T;

ld DP[10001][1001] = {0};

ld upp(ld i, ll j){

if(j == 0)return 1.0;

if(j%2 == 0){

    ld h = upp(i,j/2);
    return h*h;

}

return i * upp(i,j-1);

}

ld dp(ll i, ll l){
    if(i == 0)return 1.0 * (l == 0);
    if(l == 0)return 0;
    if(DP[i][l] != -1)return DP[i][l];
    ld ans = ld(k-l+1)/ld(k) * dp(i-1,l-1) + ld(l)/ld(k) * dp(i-1,l);
    DP[i][l] = ans;
    return ans;
}

ld f(ll i){

ld ans = 1.0;

ld r = 1.0 - 1.0/k;
ld p = upp(r , i-k+1);
for(ll c1 = 0; c1 < k; c1++){
    ans *= 1 - p;
    p *= r;
}
return ans;

}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int c1,c2,c3,c4,c5;
    ll a,b,c,d;

    ll l,r;

    for(c1 = 0; c1 < 10001; c1++){
        for(c2 = 0; c2 < 1001; c2++){
            DP[c1][c2] = -1;
        }
    }


    cin >> k >> q;

    for(c1 = 0; c1 < q; c1++){
        cin >> a;
        ld look = ld(a)/ld(2000);

        ll ans = 0;

        for(c2 = k; c2 < 10001; c2++){
            //cout << dp(c2,k) << " " << f(c2) << "\n";
            if(dp(c2,k) > look){
                ans = c2;
                break;
            }
        }

        cout << ans << "\n";

    }

    return 0;
}