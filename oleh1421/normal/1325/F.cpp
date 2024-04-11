//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC opitmize ("trapv")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int mod=1000000007;
const int N=100010;
vector<int>g[N];
int used1[N];
int deep[N];
int p[N];
vector<int>order;
int rt=0;
void dfs1(int v,int pr,int cur){
    used1[v]=1;
    deep[v]=cur;
    order.push_back(v);
    for (auto to:g[v]){
        if (to==pr || used1[to]==2) continue;
        if (used1[to]) {
            int cur=deep[v]-deep[to]+1;
            if (cur>=rt){
                cout<<2<<endl;
                cout<<cur<<endl;
                for (int i=order.size()-cur;i<order.size();i++) cout<<order[i]<<" ";
                cout<<endl;
                exit(0);
            }
//            cout<<v<<" "<<to<<" "<<deep[v]<<" "<<deep[to]<<endl;
        }
        else dfs1(to,v,cur+1);
    }
    used1[v]=2;
    order.pop_back();
}
bool used[N];
int color[N];
vector<int>ans[N];
void dfs(int v){
    used[v]=true;
    vector<int>u;
    for (auto to:g[v]){
        if (used[to]) u.push_back(color[to]);
    }
    sort(u.begin(),u.end());
    if (u.empty() || u[0]>1) color[v]=1;
    else{
        for (int i=1;i<u.size();i++){
            if (u[i]>u[i-1]+1){
                color[v]=u[i-1]+1;
                break;
            }
        }
        if (!color[v]) color[v]=u.back()+1;
    }
    ans[color[v]].push_back(v);
    for (auto to:g[v]){
        if (!used[to]) dfs(to);
    }
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    while (rt*rt<n) rt++;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1,0,0);
    dfs(1);
    int ind=0;
    for (int i=1;i<=n;i++){
        if (ans[i].size()>ans[ind].size()) ind=i;
    }
    cout<<1<<endl;
    for (int i=0;i<rt;i++) cout<<ans[ind][i]<<" ";
    return 0;
}