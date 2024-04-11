#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500005;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    map<int,ll>mp;
    ll res=0ll;
    for (int i=1;i<=n;i++){
        res+=mp[a[i]]*(n-i+1ll);
        mp[a[i]]+=i;
    }
    cout<<res<<endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}