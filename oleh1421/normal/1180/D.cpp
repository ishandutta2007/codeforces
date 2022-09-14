//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;

    vector<pair<int,int> >ans;
    for (int i=1;i<=n/2;i++){
        for (int j=1;j<=m;j++){
            ans.push_back({i,j});
            ans.push_back({n-i+1,m-j+1});

        }
    }
    if (n%2){
        for (int j=1;j<=m/2;j++){
            ans.push_back({n/2+1,j});
            ans.push_back({n/2+1,m-j+1});
        }
        if (m%2) ans.push_back({n/2+1,m/2+1});
    }
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;
    return 0;
}