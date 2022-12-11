#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e9

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    ll v[n];
    for(ll i = 0;i<n;i++) cin >> v[i];
    ll b = sqrt(n)+1;
    ll dp[n][b];
    for(int p = n-1;p>=0;p--){
        for(int j = 1;j<b;j++){
            if(p+v[p]+j>=n) dp[p][j] = 1;
            else dp[p][j] = dp[p+v[p]+j][j]+1;
        }
    }
    ll q;
    cin >> q;
    ll start,jump;
    ll ans;
    for(ll j = 0;j<q;j++){
        cin >> start >>jump;
        ans = 0;
        start--;
        if(jump<b) cout << dp[start][jump] << "\n";
        else{
            while(start < n){
                start += jump+v[start];
                ans++;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}