//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=2000010;
const ll mod=998244353;
const int L=20;
const ll inv2=(mod+1)/2;
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
int last[26];
void solve(){
    string s;cin>>s;
    for (int i=0;i<26;i++) last[i]=-1;
    for (int i=0;i<s.size();i++) last[s[i]-'a']=i;
    int mn=s.size();
    for (int i=0;i<26;i++){
        if (last[i]==-1) continue;
        mn=min(mn,last[i]);
    }
    for (int i=mn;i<s.size();i++) cout<<s[i];
    cout<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

//2
//
//1 2

/**


**/