#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int long long
using namespace std;
int len(ll a){
    int cnt=0;
    while (a){
        a/=10ll;
        cnt++;
    }
    return cnt;
}
ll dp[1000001];
ll pref[1000001];

void solve(){
    int k;cin>>k;

    int ind=0;
    while (pref[ind]<k) ind++;
    k-=pref[ind-1];
    ll cur=0ll;
    ll num=0ll;
    while (cur<k){
          cur+=len(++num);
    }
    cur-=len(num);
    k-=cur;
    vector<int>v;
    while (num){
        v.push_back(num%10ll);
        num/=10ll;
    }
    reverse(v.begin(),v.end());
    cout<<v[k-1]<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    int n=200000;
    for (int i=1;i<=n;i++) dp[i]=(dp[i-1]+len(i))*1ll;
    for (int i=1;i<=n;i++) pref[i]=(pref[i-1]+dp[i])*1ll;
    while (tt--){
        solve();
    }
    return 0;
}