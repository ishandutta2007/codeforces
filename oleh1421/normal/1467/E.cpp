//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
int add[N];
int a[N];
map<int,int>cnt;
map<int,int>mp[N];
vector<int>g[N];
void dfs(int v,int pr){
    mp[v][a[v]]++;
    int Too=-1;
    for (int to:g[v]){
        if (to!=pr){
            dfs(to,v);
            if (mp[to][a[v]]) {
                if (Too!=-1){
                    cout<<0<<endl;
                    exit(0);
                }
                Too=to;
            }
            if (mp[to].size()>mp[v].size()) mp[v].swap(mp[to]);
            for (auto cur:mp[to]){
                mp[v][cur.first]+=cur.second;
            }
        }
    }
    if (cnt[a[v]]>1){
        if (mp[v][a[v]]==cnt[a[v]]){
            add[1]++;
            add[Too]--;
        } else if (mp[v][a[v]]==1){
            add[v]++;
        } else {
            add[1]++;
        }
    }
}
int res=0;
void dfs1(int v,int pr,int cur){
    cur+=add[v];
    if (cur==0) res++;
    for (int to:g[v]){
        if (to!=pr){
            dfs1(to,v,cur);
        }
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    dfs1(1,0,0);
    cout<<res<<endl;
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