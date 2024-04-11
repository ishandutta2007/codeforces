#pragma GCC Optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
const long long mod=998244353;
typedef long long ll;
using namespace std;
mt19937_64 rng(time(NULL));
int x[300001];
map<int,int>d;
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>x[i],d[x[i]]=0;
    queue<int>q;
    for (int i=1;i<=n;i++) q.push(x[i]);
    vector<int>ans;
    ll res=0ll;
    while (ans.size()<m){
        int v=q.front();
        q.pop();
        if (d[v]){
            ans.push_back(v);
            res+=d[v]*1ll;
        }
        if (d.find(v-1)==d.end()) {
            q.push(v-1);
            d[v-1]=d[v]+1;
        }

        if (d.find(v+1)==d.end()) {
            q.push(v+1);
            d[v+1]=d[v]+1;
        }
    }
    cout<<res<<endl;

    for (auto i:ans) cout<<i<<" ";
    cout<<endl;
}
int32_t main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int tt=1;
    while (tt--){
        solve();

    }

    return 0;
}