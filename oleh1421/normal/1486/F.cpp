//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=300010;
const ll inf=10000000000007ll;
const int A=1000100;
const int L=20;
int up[N][L];
vector<int>g[N];
int a[N],b[N],lc[N],toA[N],toB[N];
int tin[N],tout[N];
int timer=0;
int vert[N];
void dfs(int v,int pr){
    up[v][0]=pr;
    for (int i=1;i<L;i++) up[v][i]=up[up[v][i-1]][i-1];
    tin[v]=++timer;
    vert[timer]=v;
    for (int to:g[v]){
        if (to!=pr){
            dfs(to,v);
        }
    }
    tout[v]=timer;
}
bool upper(int a,int b){
    return (tin[a]<=tin[b] && tout[a]>=tout[b]);
}
int lca(int a,int b){
    if (upper(a,b)) return a;
    if (upper(b,a)) return b;
    for (int i=L-1;i>=0;i--){
        if (!upper(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}
vector<int>c[N];
int t[N];
void upd(int n,int pos,int x){
    for (;pos<=n;pos|=pos+1) t[pos]+=x;
}
int get(int pos){
    int sum=0;
    for (;pos>=0;pos&=pos+1,pos--) sum+=t[pos];
    return sum;
}
void add(int l,int r,int x,int n){
    upd(n,l,x);
    upd(n,r+1,-x);
}
map<pair<int,int>,int>mp[N];
map<int,int>mp1[N],mp2[N];
int cnt[N];
vector<int>Q[N];

void solve(){
    int n,m;cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin>>m;
    for (int i=1;i<=m;i++) cin>>a[i]>>b[i];
    tin[0]=timer;
    dfs(1,0);
    tout[0]=timer;
    for (int i=1;i<=n;i++){
        for (int to:g[i]){
            if (!upper(to,i)){
                c[i].push_back(tin[to]);
            }
        }
        sort(c[i].begin(),c[i].end());
    }
    for (int i=1;i<=m;i++){
        lc[i]=lca(a[i],b[i]);
//        cout<<a[i]<<" "<<b[i]<<" "<<lc[i]<<" "<<(lc[i]==a[i])<<endl;
        toA[i]=(lc[i]==a[i] ? -1 : vert[*(--upper_bound(c[lc[i]].begin(),c[lc[i]].end(),tin[a[i]]))]);
        toB[i]=(lc[i]==b[i] ? -1 : vert[*(--upper_bound(c[lc[i]].begin(),c[lc[i]].end(),tin[b[i]]))]);
        add(tin[lc[i]],tout[lc[i]],1,n);
        if (toA[i]!=-1) add(tin[toA[i]],tout[toA[i]],-1,n);

        if (toB[i]!=-1) add(tin[toB[i]],tout[toB[i]],-1,n);
        Q[lc[i]].push_back(i);
    }
    ll res=0ll;
    for (int v=1;v<=n;v++){
        for (int i:Q[v]){
            add(tin[lc[i]],tout[lc[i]],-1,n);
            if (toA[i]!=-1) add(tin[toA[i]],tout[toA[i]],1,n);

            if (toB[i]!=-1) add(tin[toB[i]],tout[toB[i]],1,n);
        }
        for (int i:Q[v]){
            res+=get(tin[a[i]])+get(tin[b[i]])-get(tin[lc[i]])*2;
        }
        for (int i:Q[v]){
            add(tin[lc[i]],tout[lc[i]],1,n);
            if (toA[i]!=-1) add(tin[toA[i]],tout[toA[i]],-1,n);

            if (toB[i]!=-1) add(tin[toB[i]],tout[toB[i]],-1,n);
        }
    }
    for (int i=1;i<=m;i++){
        if (toA[i]==-1) toA[i]=++timer;
        if (toB[i]==-1) toB[i]=++timer;
        if (toA[i]>toB[i]) swap(toA[i],toB[i]);
        res+=cnt[lc[i]]++;
        res-=mp1[lc[i]][toA[i]]++;
        res-=mp1[lc[i]][toB[i]]++;
        res+=mp[lc[i]][{toA[i],toB[i]}]++;
    }
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