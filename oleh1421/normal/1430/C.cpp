#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
int a[N];
void solve(){
    int n;cin>>n;
    vector<pair<int,int> >ans;
    int cur=n;
    for (int i=n-1;i>=1;i--){
        ans.push_back({cur,i});
        cur+=i+1;
        cur/=2;
    }
    cout<<cur<<endl;
    for (auto p:ans) cout<<p.first<<" "<<p.second<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}