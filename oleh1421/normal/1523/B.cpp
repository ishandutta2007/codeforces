#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=500010;
int a[N];
vector<pair<int,pair<int,int> > >ans;
void op(int x,int i,int j){
    ans.push_back({x,{i,j}});
    if (x==1) a[i]=a[i]+a[j];
    else a[j]=a[j]-a[i];
}
void go(int i,int j){
    op(2,i,j);
    op(1,i,j);
    op(1,i,j);
    op(2,i,j);
    op(1,i,j);
    op(1,i,j);
}
void solve(){
    int n;cin>>n;
    ans.clear();
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n/2;i++){
        go(i,n-i+1);
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second.first<<" "<<cur.second.second<<endl;
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//x+y x-y
//
//
//x+y -2*y
//
//x-y

//x y
//x x-y
//x x-2*y