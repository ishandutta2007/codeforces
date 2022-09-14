#include<bits/stdc++.h>
typedef long long ll;

using namespace std;
#define endl '\n'
const ll mod=1000000007ll;
const int N=100010;
ll a[N];
ll pw2[N];
ll pw10[N];
ll suf[N];
ll sum[N];
void solve(){

    string s;cin>>s;
    int n=s.size();
    ll num=0ll;
    for (int i=0;i<n;i++){
        a[i+1]=(s[i]-'0');
        num*=10ll;
        num+=a[i+1];
        num%=mod;
    }
    pw2[0]=pw10[0]=1ll;
    sum[0]=1ll;
    for (int i=1;i<=n;i++){
        pw2[i]=(pw2[i-1]*2ll)%mod;
        pw10[i]=(pw10[i-1]*10ll)%mod;
        sum[i]=(sum[i-1]+pw10[i])%mod;
    }
    suf[0]=1ll;
    for (int i=1;i<=n;i++){
        suf[i]=(suf[i-1]*10ll+sum[i-1])%mod;
    }
    ll res=0ll;
    for (ll i=1;i<=n;i++){
        res+=((a[i]*suf[n-i])%mod);

        res+=((a[i]*((i*(i-1)/2ll)%mod))*pw10[n-i])%mod;
        res%=mod;
    }
    cout<<(res-num+mod)%mod<<endl;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
///try to solve I
///try to solve B(Two sets)
/*
)()(()
*/