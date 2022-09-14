#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
int a[N];
bool used[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) used[i]=false;
    for (int i=1;i<=n;i++) cin>>a[i],used[a[i]]=true;
    vector<int>v;
    for (int i=1;i<=n;i++){
        if (used[i]) v.push_back(i);
    }
    if (v.size()>k){
        cout<<"-1\n";
        return;
    }
    while (v.size()<k) v.push_back(1);
    vector<int>ans;
    for (int i=1;i<=n;i++){
        for (auto j:v) ans.push_back(j);
    }
    cout<<ans.size()<<endl;
    for (auto i:ans) cout<<i<<" ";
    cout<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
2 3
1 100
*/