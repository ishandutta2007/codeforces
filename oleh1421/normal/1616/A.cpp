#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
const int N=1500010;
const ll inf=1000000000000000001ll;
const ll mod=998244353;
void solve(){
    int n;cin>>n;
    map<int,int>mp;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        x=abs(x);
        mp[x]++;
    }
    int res=0;
    for (auto cur:mp) res+=min(cur.second,2-(cur.first==0));
    cout<<res<<endl;

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
/**




**/