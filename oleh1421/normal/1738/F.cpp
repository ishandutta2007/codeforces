#include <bits/stdc++.h>
//#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const int N=2010;
const int TSZ=1e7;
const ll inf=1e18;
const ll mod=998244353;
int d[N];
vector<int>g[N];
int c[N];
void dfs(int v,int col){
    c[v]=col;
    for (int to:g[v]){
        if (!c[to]){
            dfs(to,col);
        }
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>d[i];
    for (int i=1;i<=n;i++) {
        g[i].clear();
        c[i]=0;
    }
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        v.push_back({d[i],i});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for (auto cur:v){
        int x=cur.second;
        if (!g[x].empty()) continue;
        for (int i=1;i<=d[x];i++){
            cout<<"? "<<x<<endl;
            int ans;cin>>ans;
            bool ok=(g[ans].empty());
            g[x].push_back(ans);
            g[ans].push_back(x);
            if (!ok) break;
        }
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (!c[i]){
            dfs(i,++cnt);
        }
    }
    cout<<"! ";
    for (int i=1;i<=n;i++) cout<<c[i]<<" ";
    cout<<endl;



}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}