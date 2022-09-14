#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define endl '\n'
const int N=100010;
const ll mod=998244353;
int par_a[N],par_b[N];
int sz_a[N],sz[N];
set<pair<int,int> >st;
set<int>st1;
int get_a(int x){
    if (par_a[x]==x) return x;
    return get_a(par_a[x]);
}
int get_b(int x){
    if (par_b[x]==x) return x;
    return get_b(par_b[x]);
}
vector<int>g[N];
void unite_a(int a,int b){
    a=get_a(a);
    b=get_a(b);
    if (sz_a[a]>sz_a[b]) swap(a,b);
    st.erase({sz_a[a],a});
    st.erase({sz_a[b],b});
    for (int x:g[a]) g[b].push_back(x);
    g[a].clear();
    sz_a[b]+=sz_a[a];
    sz_a[a]=0;
    par_a[a]=b;
    st.insert({sz_a[b],b});
}
set<int>g_b[N];
void unite_b(int a,int b){
    a=get_b(a);
    b=get_b(b);
    if (sz[a]>sz[b]) swap(a,b);
    for (int x:g_b[a]) g_b[b].insert(x);
    g_b[a].clear();
    st1.erase(a);
    par_b[a]=b;
    sz[b]+=sz[a];
    sz[a]=0;
}
void solve(){
    int n,m1,m2;cin>>n>>m1>>m2;
    for (int i=1;i<=n;i++){
        sz_a[i]=sz[i]=1;
        par_a[i]=par_b[i]=i;
        st.insert({1,i});
        st1.insert(i);
        g[i].push_back(i);
        g_b[i].insert(i);
    }
    if (m1<m2){
        for (int i=1;i<=m1;i++){
            int a,b;cin>>a>>b;
            unite_b(a,b);
        }
        for (int i=1;i<=m2;i++){
            int a,b;cin>>a>>b;
            unite_a(a,b);
        }
        swap(m1,m2);

    } else {
        for (int i=1;i<=m1;i++){
            int a,b;cin>>a>>b;
            unite_a(a,b);
        }
        for (int i=1;i<=m2;i++){
            int a,b;cin>>a>>b;
            unite_b(a,b);
        }
    }
    vector<pair<int,int> >ans;
    for (int it=1;it<=n-m1-1;it++){
        int V=(*st.begin()).second;
        for (int v:g[V]) {
            int cur=get_b(v);
            sz[cur]--;
            g_b[cur].erase(v);
            if (sz[cur]==0) st1.erase(cur);
        }
        for (int v:g[V]) {
            int cur=get_b(v);
            if (sz[cur]>0) st1.erase(cur);
            if (!st1.empty()){
                int cur1=(*st1.begin());
                ans.push_back({v,*g_b[cur1].begin()});
                if (sz[cur]>0) st1.insert(cur);
                break;
            }
            if (sz[cur]>0) st1.insert(cur);
        }
        for (int v:g[V]) {
            int cur=get_b(v);
            if (sz[cur]==0) st1.insert(cur);
            sz[cur]++;
            g_b[cur].insert(v);
        }
//        int x=ans.back().first;
//        int y=ans.back().second;
//        if (get_a(x))
        unite_a(ans.back().first,ans.back().second);
        unite_b(ans.back().first,ans.back().second);
    }
    cout<<n-m1-1<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;
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
/*
ba
ca
aca
a
b
c
ac
*/