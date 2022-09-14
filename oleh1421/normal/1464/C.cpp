//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100010;
ll cnt[30];
ll pref[30];
void solve(){
    int n;cin>>n;
    ll T;cin>>T;
    string s;cin>>s;
    T-=(1ll<<(s.back()-'a'));
    s.pop_back();
    T+=(1ll<<(s.back()-'a'));
    s.pop_back();
    n-=2;
    for (auto i:s) T+=(1ll<<(i-'a')),cnt[i-'a'+1]++;
    if (T<0 || T%2ll){
        cout<<"No\n";
        return;
    }
    ll sum=0ll;
    ll pref=0ll;
    for (int i=1;i<30;i++){
        sum+=(cnt[i]<<i);
        if (T&(1ll<<i)) pref+=(1ll<<i);
        if (sum<pref){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}