#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int T; cin>>T;
    while(T--){
        int n, k;
        cin>>n>>k;
        vector<ll> a(n+1), s(n+1);
        fors(i,1,n+1) cin>>a[i], s[i] = s[i-1]+a[i];
        if(n <= k){
            ll ans = s[n] + (ll)(k-1LL+k-n)*n/2;
            cout<<ans<<endl;
        }else{
            ll ans = (ll)(k-1)*k/2;
            ll mx = 0;
            for(int i = k; i <= n; ++i) mx = max(mx, s[i]-s[i-k]);
            ans += mx;
            cout<<ans<<endl;
        }
    }
    return 0;
}