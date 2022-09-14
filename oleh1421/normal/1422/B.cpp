#include<bits/stdc++.h>
typedef long long ll;

using namespace std;
#define endl '\n'
const int N=110;
int a[N][N];
ll solve(vector<int>v){
    sort(v.begin(),v.end());
    ll m=v[((int)v.size()+1)/2-1];
    ll res=0ll;
    for (ll i:v){
        res+=abs(m-i);
    }
    return res;
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    ll res=0ll;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            res+=solve({a[i][j],a[n-i+1][j],a[i][m-j+1],a[n-i+1][m-j+1]});
        }
    }
    cout<<res/4ll<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
///try to solve I
///try to solve B(Two sets)
/*
)()(()
*/