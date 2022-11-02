#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const long long int N=1e2+30;
ll dp[N][N],sum1[N],sum2[N];
vector <ll> one,two;
int main(){
	ios_base::sync_with_stdio(false); cout.tie(0);
	cin.tie(0);
    ll n;
    cin >> n;
    rep (i,0,n){
        ll x,y;
        cin >> x >> y;
        if (x == 1){
            one.pb(y);
        }
        else{
            two.pb(y);
        }
    }
    sort(one.begin(),one.end());
    sort(two.begin(),two.end());
    sum1[0] = 0;
    sum2[0] = 0;
    ll s=one.size(),sz=two.size();
    rep (i,1,s+1){
        sum1[i] = sum1[i-1] + one[i-1];
    }
    rep (i,1,sz+1){
        sum2[i] = sum2[i-1] + two[i-1];
    }
    ll ans = 5000;
    rep(i,0,s+1){
        rep(j,0,sz+1){
            if (i+2*j >= sum1[s-i]+sum2[sz-j]){
                ans = min(ans,i+2*j);
            }
        }
    }
    cout << ans;
    return 0;
}