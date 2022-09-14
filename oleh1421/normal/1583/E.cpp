//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=2000010;
int a[N],b[N];
vector<int>G[N];
vector<pair<int,int> >g[N];
int cnt[N];
int ind[N];
bool used[N];
vector<pair<int,int> >order;
void dfs(int v,int pr){
    while (ind[v]<g[v].size()){
        if (used[g[v][ind[v]].second]){
            ind[v]++;
            continue;
        }
        used[g[v][ind[v]].second]=true;
        dfs(g[v][ind[v]].first,g[v][ind[v]].second);
    }
    order.push_back({v,pr});
}
int n,m;
int ind1[N];
int p[N];
void dfs1(int v){
    for (int to:G[v]){
        if (p[to]==0){
            p[to]=v;
            dfs1(to);
        }
    }
}
vector<int>get_path(int a,int b){
    p[a]=-1;
    dfs1(a);
    vector<int>v;
    while (b!=a){
        v.push_back(b);
        b=p[b];
    }
    v.push_back(a);
    reverse(v.begin(),v.end());
    for (int i=1;i<=n;i++) p[i]=0;
    return v;
}
vector<int>ans[N];
void solve(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int q;cin>>q;
    for (int i=1;i<=q;i++) cin>>a[i]>>b[i],g[a[i]].push_back({b[i],i}),g[b[i]].push_back({a[i],i});
    int CNT=0;
    for (int i=1;i<=n;i++){
        if (g[i].size()%2){
            CNT++;
        }
    }
    if (CNT){
        cout<<"NO\n";
        cout<<CNT/2<<endl;
        return;
    }
    vector<vector<pair<int,int> > >V;
    for (int i=1;i<=n;i++){
        dfs(i,0);
        V.push_back(order);
        order.clear();
    }
    for (auto order:V){
        if (order.size()<=1) continue;
        reverse(order.begin(),order.end());
//        for (auto i:order) cout<<i.first<<" ";
//        cout<<endl;
        ind1[order[0].first]=1;
        vector<int>v;
        v.push_back(order[0].first);
        for (int j=1;j<order.size();j++){

            vector<int>P=get_path(v.back(),order[j].first);
            int ind=0;
            for (int t=1;t<P.size();t++){
                if (ind1[P[t]]) ind=t;
            }
            while (v.back()!=P[ind]){
                ans[order[j].second].push_back(v.back());
                ind1[v.back()]=0;
                v.pop_back();
            }
            ans[order[j].second].push_back(v.back());
            for (int t=ind+1;t<P.size();t++) {
                ans[order[j].second].push_back(P[t]);
                v.push_back(P[t]);
                ind1[P[t]]=v.size();
            }
        }
        ind1[v.back()]=0;
    }
    cout<<"YES\n";
//    cout<<ans[2].size()<<endl;
    for (int i=1;i<=q;i++){
        if (ans[i].empty()) return;
        if (ans[i].back()==a[i]){
            reverse(ans[i].begin(),ans[i].end());
        }
        cout<<ans[i].size()<<endl;
        for (int x:ans[i]) cout<<x<<" ";
        cout<<endl;
    }


}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

/**
5
1
1
2
1
0
2
4
0
1
4

**/