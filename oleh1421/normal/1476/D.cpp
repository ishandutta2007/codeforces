//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=301019;
const ll mod=1000000007ll;
vector<int>g[N][2];
bool used[N][2];
vector<int>order;
set<int>st;
void dfs(int v,int c){
    used[v][c]=true;
    if (!c) order.push_back(v);
    st.insert(v);
    for (int to:g[v][c]){
        if (!used[to][c^1]){
            dfs(to,c^1);
        }
    }
}
int dp[N];
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    for (int i=0;i<=n;i++){
        for (int j=0;j<2;j++){
            g[i][j].clear();
            used[i][j]=0;
        }
    }
    for (int i=0;i<n;i++){
        if (s[i]=='R'){
            g[i][0].push_back(i+1);
            g[i+1][1].push_back(i);
        } else {
            g[i][1].push_back(i+1);
            g[i+1][0].push_back(i);
        }
    }
    for (int i=0;i<=n;i++){
        if (used[i][0]) continue;
        order.clear();
        st.clear();
        dfs(i,0);
        for (int x:order){
            dp[x]=st.size();
        }
    }
    for (int i=0;i<=n;i++) cout<<dp[i]<<" ";
    cout<<endl;


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
/*
1
2
RL
*/