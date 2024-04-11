//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define int ll
#define endl '\n'
const int N=2000100;
const ll mod=998244353;
const ll inf=2000000000000000000;
vector<int>a[N];
bool ban[N];
set<int>g[N];
set<int>in[N];
set<int>out[N];
bool used[N];
vector<int>order;
void dfs(int v){
    order.push_back(v);
    used[v]=true;
    for (int to:g[v]){
        if (!used[to]) dfs(to);
    }
}
ll dp[N];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        int len;cin>>len;
        a[i].resize(len,0);
        set<int>st;
        for (int &j : a[i]) cin>>j,st.insert(j);
        if (st.size()<len){
            for (int x:st) ban[x]=true;
        } else {
            for (int j=1;j<a[i].size();j++){
                g[a[i][j-1]].insert(a[i][j]);
                g[a[i][j]].insert(a[i][j-1]);
                out[a[i][j-1]].insert(a[i][j]);
                in[a[i][j]].insert(a[i][j-1]);
            }
        }
    }
    map<int,int>block;
    for (int i=1;i<=k;i++){
        if (used[i]) continue;
        dfs(i);
        bool OK=true;
        if (order.size()>1){
            int s=0,f=0,mid=0;
            for (int j:order){
                if (ban[j]) OK=false;
                if (in[j].size()==1 && out[j].size()==1) mid++;
                else if (in[j].size()==1 && out[j].size()==0) f++;
                else if (in[j].size()==0 && out[j].size()==1) s++;
            }
            if (s!=1 || f!=1 || mid+2!=order.size()) OK=false;
        } else OK=(!ban[i]);
        if (OK) block[order.size()]++;
        order.clear();
    }
    vector<pair<int,int> >v;
    for (auto cur:block) v.push_back(cur);
    dp[0]=1ll;
    for (int i=1;i<=m;i++){
        dp[i]=0ll;
        for (auto cur:v){
            if (i>=cur.first){
                dp[i]+=dp[i-cur.first]*cur.second;
                dp[i]%=mod;
            }
        }
    }
    cout<<dp[m]<<endl;
 
 
 
 
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
 
//10
//01
//01
//10
//
//10
//10
//
//01
//01
//
//11
//00
//
//00
//11
/**
2 2 4
1 1 1
1 2 1
2 1 1
1 1 0
 
**/