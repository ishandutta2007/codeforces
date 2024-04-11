//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=500010;
const ll inf=2e18;
const ll mod=1000000007;

void solve(int Case){
    int n,m;cin>>n>>m;
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            if (c=='R') v.push_back({i,j});
        }
    }
    sort(v.begin(),v.end());

    for (auto cur:v){
        if (cur.second<v[0].second){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";


}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**

**/