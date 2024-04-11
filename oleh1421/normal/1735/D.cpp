#include <bits/stdc++.h>
#define endl '\n'
#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const ll inf=1e18;
const int N=1010;
int c[N][22];
void solve(){
    int n,k;cin>>n>>k;
    set<ll>cards;
    for (int i=1;i<=n;i++){
        ll cur=0ll;
        for (int j=0;j<k;j++) {
            cin>>c[i][j];
            cur*=3ll;
            cur+=c[i][j];
        }
        cards.insert(cur);
    }
    map<ll,int>mp;
    ll res=0ll;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            ll cur=0;
            for (int t=0;t<k;t++){
                int x=(6-c[i][t]-c[j][t])%3;
                cur*=3;
                cur+=x;
            }
            if (cards.count(cur)) res+=(mp[cur]++);
        }
    }
    cout<<res<<'\n';





}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}