#include <bits/stdc++.h>
#define ll int
#define x first
#define y second
#pragma GCC optimize ("O3")
using namespace std;
ll N,memo[1<<25];
pair<ll,ll> arr[30];
ll dist (ll a,ll n){
    ll k1=arr[n].x-arr[a].x;
    ll k2=arr[n].y-arr[a].y;
    return k1*k1 + k2*k2;
}
ll dp(ll mask){
    if (__builtin_popcount(mask)==N){
        return 0;
    }
    if (memo[mask]!=0) return memo[mask];
    ll res=1e9;
    for (ll i=1; i<=N; i++){
        if (!( (mask>>(i-1) &1))){
            res= min(res, dp(mask|(1<<(i-1))) + 2*dist(i,0));
            for (ll j=i+1; j<=N; j++){
                if (!(mask>>(j-1) &1) and i!=j){
                    res=min(res, dp(mask|(1<<(i-1))|(1<<(j-1))) +dist(i,0)+dist(i,j)+dist(j,0));
                }
            }
            break;
        }
    }
    memo[mask]=res;
    return res;
}
void backtrack (ll mask){
    if (__builtin_popcount(mask)==N){
        return;
    }
    for (ll i=1; i<=N; i++){
        if (!( (mask>>(i-1) &1))){
            if (dp(mask|(1<<(i-1))) + 2*dist(i,0) == dp(mask)){
                cout << 0 << " " << i << " "; 
                backtrack(mask|(1<<(i-1)));
                return;
            }
            for (ll j=i+1; j<=N; j++){
                if (!(mask>>(j-1) &1) and i!=j){
                    if (dp(mask|(1<<(i-1))|(1<<(j-1)))+dist(i,0)+dist(i,j)+dist(j,0) == dp(mask)){
                        cout << 0 << " " << i << " " << j << " ";
                        backtrack(mask|(1<<(i-1))|(1<<(j-1)));
                        return;
                    }
                }
            }
            break;
        }
    }
    return;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // memset(memo,-1,sizeof(memo));
    cin >> arr[0].x >> arr[0].y;
    cin>>N;
    for (int i=1; i<=N; i++) cin >> arr[i].x >> arr[i].y;
    cout << dp(0) << endl;
    backtrack(0);
    cout << 0 << endl;
}