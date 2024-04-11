#include <bits/stdc++.h>

typedef long long ll;
//#define endl '\n'
using namespace std;
//#define int ll
const int N=500010;
const ll mod=1000000007;

void solve(){
    vector<pair<int,int> >ans;
    int n;cin>>n;
    cout<<"? "<<1<<endl;
    vector<int>v,u;

    for (int i=1;i<=n;i++){
        int x;cin>>x;
        if (x%2==0 && x>0) v.push_back(i);
        else if (x>0) u.push_back(i);
        if (x==1){
            ans.push_back({1,i});
        }
    }
    if (u.size()<v.size()){
        ans.clear();
        v=u;
    }
    for (int r:v){
        cout<<"? "<<r<<endl;
        for (int i=1;i<=n;i++){
            int x;cin>>x;
            if (x==1){
                ans.push_back({r,i});
            }
        }
    }
    cout<<"! "<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;


}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}