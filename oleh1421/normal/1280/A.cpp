#include <bits/stdc++.h>
typedef long long ll;
const long long mod=1000000007ll;
#define endl '\n'
using namespace std;
void solve(){
    ll x;cin>>x;
    string s;cin>>s;
    ll l=0;
    while (s.size()<x){
        l++;
        int num=(s[l-1]-'1');
        if (!num) continue;
        string cur="";
        for (int i=l;i<s.size();i++) cur+=s[i];
        for (int i=0;i<num;i++) s+=cur;
    }
    ll sz=(int)s.size()*1ll;
    for (ll i=l+1;i<=x;i++){
        ll num=(s[i-1]-'1')*1ll;
        sz+=((mod+sz-i)*num)%mod;
        sz%=mod;
        //cout<<i<<" "<<sz<<endl;
    }
    cout<<sz<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}