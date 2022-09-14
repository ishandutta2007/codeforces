
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
const ll mod=1000000007ll;
int pr[N];
int go[N];
vector<int>seg[N];
int c[N];
bool used[N];
int ps[N];
vector<int>g[N];
int was[N];
void dfs(int v){
    was[v]=1;
    for (int to:g[v]){
        if (was[to]){
            if (was[to]==1){
                cout<<"0\n";
                exit(0);
            }
        } else dfs(to);
    }
    was[v]=2;
}
int d[N];
int ans[N];
int pos[N];
int dp[N];
void dfs1(int v){
    dp[v]=1;
    for (int to:g[v]){
        if (!dp[to]) dfs1(to);
        dp[v]=max(dp[v],dp[to]+1);
    }
}
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>pr[i];
    for (int i=1;i<=k;i++){
        int x;cin>>x;
        cin>>go[x];
        used[go[x]]=true;
    }
    int cn=0;
    c[0]=0;
    seg[0].push_back(0);
    ps[0]=1;
    for (int i=1;i<=n;i++){
        if (!used[i]){
//            cout<<i<<endl;
            cn++;
            int v=i;
            while (go[v]){
                seg[cn].push_back(v);
                c[v]=cn;
                ps[v]=seg[cn].size();
                v=go[v];
            }
            seg[cn].push_back(v);
            c[v]=cn;
            ps[v]=seg[cn].size();
//            cout<<v<<" "<<go[v]<<endl;
        }
    }
    for (int i=1;i<=n;i++) {
        if (!c[i]){
            cout<<"0\n";
            return;
        }
    }
    for (int i=1;i<=n;i++){
        if (c[i]==c[pr[i]]){
            if (ps[i]<ps[pr[i]]){
                cout<<"0\n";
                return;
            }
        } else {
            g[c[pr[i]]].push_back(c[i]);
//            cout<<c[pr[i]]<<" "<<c[i]<<endl;
        }
    }
//    cout<<"OOK\n";
    dfs(0);
    dfs1(0);
    vector<pair<int,int> >order;
    for (int i=0;i<=cn;i++) order.push_back({-dp[i],i});
    sort(order.begin(),order.end());
    int cur=0;
    for (auto i:order){
        for (int j:seg[i.second]) ans[++cur]=j,pos[j]=cur;

    }
//    for (int i=1;i<=n;i++){
//        if (d[c[pr[i]]]>d[c[i]]){
//            cout<<"0\n";
//            return;
//        }
//    }
    for (int i=2;i<=n+1;i++) cout<<ans[i]<<" ";
    cout<<endl;



}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/*
*/