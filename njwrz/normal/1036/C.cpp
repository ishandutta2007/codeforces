#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll di[20];
ll dp[2][20][20];
ll get(ll x) {
    ll sz=0;
    while(x){
        di[sz++]=x%10;
        x/=10;
    }
    return sz;
}
ll sol(ll t,ll idx,ll cnt) {
    if(idx<0)return(cnt<4);
    if(dp[t][idx][cnt]!=-1)return dp[t][idx][cnt];
    ll ans=0;
    for(ll i=0,r=t?di[idx]:9;i<=r;i++)
    	ans+=sol(t&(i==r),idx-1,cnt+(i>0));
    return dp[t][idx][cnt]=ans;
}
ll sup(ll x) {
    ll sz = get(x);
    for(ll i=0;i<sz;i++){
        for(ll j=0;j<sz;j++){
            dp[0][i][j]=-1;
            dp[1][i][j]=-1;
        }
    }
    ll ans=sol(1,sz-1,0);
    return ans;
}
int main(){
    ll a,b,n;
    cin>>n;
    while(n--){
        cin>>a>>b;
        cout<<sup(b)-sup(a-1)<<'\n';
    }
}