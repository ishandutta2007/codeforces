#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
map<int,int>mp[N];
vector<pair<int,int> >g[N];
bool good[N];
int c[N];
int w[N];
int x[N];
int y[N];
int tin[N];
int fup[N];
bool bridge[N];
int timer=0;
bool used[N];
void dfs(int v,int pr){
    tin[v]=fup[v]=++timer;
    used[v]=true;
    for (auto cur:g[v]){
        int to=cur.first;
        int ind=cur.second;
        if (to==pr) continue;
        if (used[to]) fup[v]=min(fup[v],tin[to]);
        else {
            dfs(to,v);
            fup[v]=min(fup[v],fup[to]);
            if (tin[v]<fup[to]) bridge[ind]=true;
        }
    }
}
int comp[N];
ll sum[N];
int cnt[N];
ll cc[N];

void dfs1(int v,int num){
    comp[v]=num;
    cc[num]+=c[v];
    cnt[num]+=good[v];
    for (auto cur:g[v]){
        int to=cur.first;
        int ind=cur.second;
        if (!bridge[ind] && !comp[to]){
            dfs1(to,num);
        }
    }
}
vector<pair<int,int> >t[N];
int n,m,k;
ll dp[N];
int sz[N];
void dfs2(int v,int pr){
    bool ok=false;
    sz[v]=cnt[v];
    sum[v]=cc[v];

    for (auto cur:t[v]){
        int to=cur.first;
        int ww=cur.second;
        if (to!=pr){
            dfs2(to,v);
            if (sz[to]==k) ok=true;
            sz[v]+=sz[to];
            sum[v]+=sum[to];
        }
    }
    dp[v]=cc[v];
    for (auto cur:t[v]){
        int to=cur.first;
        int ww=cur.second;
        if (to!=pr){
            if (sz[to]==0) dp[v]+=sum[to];
            else if (sz[to]==k) dp[v]+=dp[to];
            else dp[v]+=max(dp[to]-ww,0ll);
        }
    }

}
ll ans[N];
void dfs3(int v,int pr){
    ans[v]=dp[v];
//    cout<<v<<" "<<ans[v]<<endl;
    for (auto cur:t[v]){
        int to=cur.first;
        int ww=cur.second;
        if (to!=pr){
            int sz_to=sz[v];
            int sz_v=sz[v]-sz[to];
            ll sum_to=sum[v];
            ll sum_v=sum[v]-sum[to];
            ll dp_v=dp[v];
            if (sz[to]==0) dp_v-=sum[to];
            else if (sz[to]==k) dp_v-=dp[to];
            else dp_v-=max(dp[to]-ww,0ll);
            ll dp_to=dp[to];
            if (sz_v==0) dp_to+=sum_v;
            else if (sz_v==k) dp_to+=dp_v;
            else dp_to+=max(dp_v-ww,0ll);

            swap(sz[v],sz_v);
            swap(sum[v],sum_v);
            swap(dp[v],dp_v);
            swap(sz[to],sz_to);
            swap(sum[to],sum_to);
            swap(dp[to],dp_to);
            dfs3(to,v);

            swap(sz[v],sz_v);
            swap(sum[v],sum_v);
            swap(dp[v],dp_v);
            swap(sz[to],sz_to);
            swap(sum[to],sum_to);
            swap(dp[to],dp_to);
        }
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=k;i++){
        int x;cin>>x;
        good[x]=true;
    }
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=m;i++){
        cin>>w[i];

    }
    for (int i=1;i<=m;i++){
        cin>>x[i]>>y[i];
        g[x[i]].push_back({y[i],i});
        g[y[i]].push_back({x[i],i});
    }
    dfs(1,0);
    int num=0;
    for (int i=1;i<=n;i++){
        if (!comp[i]){
            num++;
            dfs1(i,num);
        }
    }
    for (int i=1;i<=m;i++){
        if (bridge[i]){
            t[comp[x[i]]].push_back({comp[y[i]],w[i]});
            t[comp[y[i]]].push_back({comp[x[i]],w[i]});
        }
    }
    dfs2(1,0);
    dfs3(1,0);
    for (int i=1;i<=n;i++) cout<<ans[comp[i]]<<" ";
    cout<<endl;
    return 0;
}
/*
5 4 2
4 5
1 1 1 1 1
1 1 5 5

1 2
1 3
3 4
3 5

*/