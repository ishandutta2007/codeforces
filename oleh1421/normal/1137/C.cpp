//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=5000010;
const ll inf=1e18;
const ll mod=998244353;
bool good[N];
vector<int>g[N];
int order[N];
bool used[N];
int cmp[N];
int a[N];
int dp[N];
pair<int,int>E[N];
int pos=0;
void dfs(int v){
    vector<int>st={v};
    while (!st.empty()){
        int v=st.back();
        used[v]=true;
        if (g[v].empty()){
            order[++pos]=v;
            st.pop_back();
        } else {
            if (!used[g[v].back()]) st.push_back(g[v].back());
            g[v].pop_back();
        }
    }
}
//void dfs1(int v,int cur){
//    vector<int>st={v};
//    while (!st.empty()){
//        cmp[v]=cur;
//        used[v]=true;
//        int v=st.back();
//        if (g[v].empty()){
//            st.pop_back();
//        } else {
//            if (!used[g[v].back()]) st.push_back(g[v].back());
//            g[v].pop_back();
//        }
//    }
//}
void dfs1(int v,int cur){
    cmp[v]=cur;
    used[v]=true;
    for (int to:g[v]){
        if (!used[to]){
            dfs1(to,cur);
        }
    }
}
void dfs2(int v){
    used[v]=true;
    dp[v]=a[v];
    for (int to:g[v]){
        if (!used[to]){
            dfs2(to);
        }
        dp[v]=max(dp[v],dp[to]+a[v]);
    }
}

void solve(int Case){
    int n,m,d;cin>>n>>m>>d;
    int M=0;
    for (int it=1;it<=m;it++){
        int a,b;cin>>a>>b;
        for (int i=0;i<d;i++){
            E[++M]={(a-1)*d+i,(b-1)*d+(i+1)%d};
            g[(a-1)*d+i].push_back((b-1)*d+(i+1)%d);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<d;j++){
            char c;cin>>c;
            good[(i-1)*d+j]=c-'0';
        }
    }

    for (int i=0;i<n*d;i++){
        if (!used[i]){
            dfs(i);
        }
    }
    for (int i=0;i<n*d;i++) used[i]=false;
    for (int i=0;i<n*d;i++) g[i].clear();
    for (int i=1;i<=M;i++){
        auto cur=E[i];
        g[cur.second].push_back(cur.first);
    }
    int cnt=0;
    for (int i=pos;i>=1;i--){
        if (!used[order[i]]){
            dfs1(order[i],++cnt);
        }
    }
    for (int i=0;i<n*d;i++) {
        g[i].clear(),used[i]=false;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<d;j++){
            if (good[(i-1)*d+j]){
                if (!used[cmp[(i-1)*d+j]]){
                    a[cmp[(i-1)*d+j]]++;
                    used[cmp[(i-1)*d+j]]=true;
                }
            }
        }
        for (int j=0;j<d;j++){
            if (good[(i-1)*d+j]){
                used[cmp[(i-1)*d+j]]=false;
            }
        }
    }
    for (int i=1;i<=M;i++){
        auto cur=E[i];
        if (cmp[cur.first]!=cmp[cur.second]) g[cmp[cur.first]].push_back(cmp[cur.second]);
//        cout<<cmp[cur.first]<<" "<<cmp[cur.second]<<endl;
    }
    dfs2(cmp[0]);
    cout<<dp[cmp[0]]<<endl;







}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**
1111111100000
11010110

problem B with higher constrains


3
1 R
5 R
10 R
100 G
3 G
7 G


1
4
2 3 1 4

8 1
1 3 5 2 4 7 6 8
1 8


1
5 2
-1 1 2 0 0


4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/