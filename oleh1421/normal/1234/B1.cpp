#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
map<int,bool>used;
void solve(){
    int n,k;cin>>n>>k;
    deque<int>dq;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        if (used[x]) continue;
        if (dq.size()==k){
            used[dq.front()]=false;
            dq.pop_front();
        }
        dq.push_back(x);
        used[x]=true;
    }
    vector<int>v;
    for (auto i:dq) v.push_back(i);
    reverse(v.begin(),v.end());
    cout<<v.size()<<endl;
    for (auto i:v) cout<<i<<" ";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;tt=1;
    while (tt--){
        solve();
    }
    return 0;
}