//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=200025;
int a[N];
int b[N];
int c[N];
int cnt[N][2];
int mn_p[N];
vector<int>g[N];
ll res=0ll;
void dfs(int v,int pr,int mn){
    if (a[v]<a[mn]) mn=v;
    mn_p[v]=mn;
    if (b[v]!=c[v]){
        cnt[mn][c[v]]++;
    }
    for (auto to:g[v]){
        if (to!=pr){
            dfs(to,v,mn);
        }
    }
}
void dfs1(int v,int pr){
    for (auto to:g[v]){
        if (to!=pr){
            dfs1(to,v);
//            cnt[v][0]+=cnt[to][0];
//            cnt[v][1]+=cnt[to][1];
        }
    }
    int cur=min(cnt[v][0],cnt[v][1]);
    res+=(ll)a[v]*(ll)cur;

    cnt[v][0]-=cur;
    cnt[v][1]-=cur;
    cnt[mn_p[pr]][0]+=cnt[v][0];
    cnt[mn_p[pr]][1]+=cnt[v][1];
}
void solve(){
    int n;cin>>n;
    int sumc=0,sumb=0;
    a[0]=1000000001;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i],sumb+=b[i],sumc+=c[i];

    for (int i=0;i<=n+1;i++) g[i].clear();
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (sumb!=sumc){
        cout<<-1<<endl;
        return;
    }

    dfs(1,0,0);
    res=0ll;
    dfs1(1,0);
    cout<<res*2ll<<endl;

}
int main()
{
//    freopen("fuel.in","r",stdin);
//    freopen("fuel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}