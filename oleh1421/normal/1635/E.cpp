#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=300010;
const ll inf=4e18;
const int L=20;
char ori[N];
int x[N];
vector<pair<int,int> >g[N];
int a[N],b[N],c[N];
int used[N];
vector<int>order;
void dfs(int v){
    order.push_back(v);
    for (auto cur:g[v]){
        int to=cur.first;
        if (used[to]==used[v]){
            cout<<"NO\n";
            exit(0);
        }
        if (used[to]) continue;
        used[to]=(used[v]^3);
        dfs(to);
    }
}
bool bad=false;
int used1[N];
vector<int>topo;
void dfs2(int v){
    used1[v]=1;
    for (auto cur:g[v]){
        int to=cur.first;
        int w=cur.second;
        if (used[v]==w) continue;
        if (used1[to]==1){
            bad=true;
            continue;
        }
        if (!used1[to]){
            dfs2(to);
        }
    }
    used1[v]=2;
    topo.push_back(v);
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>c[i]>>a[i]>>b[i];
        g[a[i]].push_back({b[i],c[i]});
        g[b[i]].push_back({a[i],c[i]});
    }
    int L=0;
    for (int i=1;i<=n;i++){
        if (x[i]) continue;
        used[i]=1;
        dfs(i);
        bad=false;
        for (int j:order){
            used1[j]=false;
        }
        for (int j:order){
            if (!used1[j]){
                dfs2(j);
            }
        }
        if (bad){
            for (int j:order) used[j]^=3,used1[j]=0;
            topo.clear();
            bad=false;
            for (int j:order){
                if (!used1[j]){
                    dfs2(j);
                }
            }
        }
        if (bad){
            cout<<"NO\n";
            return;
        }
        for (int j:order){
            if (used[j]==2) ori[j]='L';
            else ori[j]='R';
        }
        order.clear();
        reverse(topo.begin(),topo.end());
        for (int j:topo){
            x[j]=++L;
        }
        topo.clear();
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++){
        cout<<ori[i]<<" "<<x[i]<<endl;
    }




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
/**
12837720
**/