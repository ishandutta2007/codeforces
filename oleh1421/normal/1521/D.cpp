#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
#define __int128_t ll
const int N=200010;
const ll mod=1000000007;
vector<int>g[N];
vector<int>t[N];
int dp[N][3];
vector<int>take[N][3];
void dfsinit(int v,int pr){
    g[v].clear();
    for (int to:t[v]){
        if (to==pr) continue;
        g[v].push_back(to);
        dfsinit(to,v);
    }
}

int val[N];
void dfs(int v,int pr){

    int sum=0;
    int mn1=0,mn2=0;
    for (int to:g[v]){
        dfs(to,v);
        sum+=min({dp[to][0],dp[to][1],dp[to][2]});
        val[to]=min(dp[to][0],dp[to][1])-min({dp[to][0],dp[to][1],dp[to][2]});
        if (val[to]<val[mn2]) mn2=to;
        if (val[mn2]<val[mn1]) swap(mn1,mn2);

    }
    dp[v][0]=dp[v][1]=dp[v][2]=sum;
    dp[v][0]++;
    dp[v][1]+=val[mn1];
    dp[v][2]+=val[mn1]+val[mn2]-1;
    take[v][0]={};
    take[v][1]={mn1};
    take[v][2]={mn1,mn2};


}
vector<pair<int,int> >bad,good;
void dfs1(int v,int pr,int need){
    for (int to:g[v]){
        bool ok=true;
        for (int to1:take[v][need]){
            if (to==to1) ok=false;
        }
        if (!ok) continue;
        int need1=0;
        for (int i=1;i<3;i++){
            if (dp[to][i]<dp[to][need1]) need1=i;
        }
        dfs1(to,v,need1);
        bad.push_back({v,to});
    }
    for (int to:take[v][need]){
        int need1=0;
        for (int i=1;i<2;i++){
            if (dp[to][i]<dp[to][need1]) need1=i;
        }
        dfs1(to,v,need1);
        good.push_back({v,to});
    }
}
int last=-1;
bool used[N];
void dfs2(int v){
    last=v;
    used[v]=true;
    for (int to:g[v]){
        if (!used[to]){
            dfs2(to);
        }
    }
}
bool S=true;
void solve(){
    val[0]=1000000001;
    int n;cin>>n;
    for (int i=1;i<=n;i++) {
        t[i].clear();
        g[i].clear();

        used[i]=false;
    }
    bad.clear();
    good.clear();
    for (int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    dfsinit(1,0);
    dfs(1,0);
    int x=0;
    if (dp[1][1]<dp[1][0]) x=1;
    if (dp[1][2]<dp[1][x]) x=2;
    //if (!S) exit(0);

    dfs1(1,0,x);
    for (int i=1;i<=n;i++) g[i].clear();
    for (auto cur:good){
        g[cur.first].push_back(cur.second);
        g[cur.second].push_back(cur.first);
    }
    last=-1;
    vector<pair<int,int> >F;
    for (int i=1;i<=n;i++){
        if (g[i].size()<=1 && !used[i]){
            if (last!=-1) F.push_back({last,i});
            dfs2(i);
        }
    }
    cout<<bad.size()<<endl;
    for (int i=0;i<bad.size();i++){
        cout<<bad[i].first<<" "<<bad[i].second<<" "<<F[i].first<<" "<<F[i].second<<endl;
    }
//    for (auto cur:bad){
//        cout<<cur.first<<" "<<cur.second<<endl;
//    }
//    cout<<ans.size()<<endl;
//    for (auto cur:ans){
//        cout<<cur.first.first<<" "<<cur.first.second<<" "<<cur.second.first<<" "<<cur.second.second<<endl;
//    }


}
int32_t main()
{
//    cout<<mod<<endl;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    if (tt!=2) S=false;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
9
1 2
3 4
2 4
2 5
1 6
4 7
6 8
6 9

*/