//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=1010;
int a[N][N];
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int> > >ans;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c-'0');
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]){
                int di,dj;
                if (i==1) di=1;
                else di=-1;
                if (j==1) dj=1;
                else dj=-1;
                ans.push_back({{i,j},{i,j+dj},{i+di,j}});
                ans.push_back({{i,j},{i,j+dj},{i+di,j+dj}});
                ans.push_back({{i,j},{i+di,j+dj},{i+di,j}});
            }
        }
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans){
        for (auto cur1:cur) cout<<cur1.first<<" "<<cur1.second<<" ";
        cout<<endl;
    }
}
int32_t main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}