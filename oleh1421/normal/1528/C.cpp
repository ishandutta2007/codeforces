#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
const int L=20;
const ll mod=998244353;
int a[N],b[N];
vector<int>tt[N],g[N];
int tin[N],tout[N];
int timer=0;
int par[N];
void dfs1(int v){
    tin[v]=++timer;
    for (int to:tt[v]){
        dfs1(to);
    }
    tout[v]=timer;
    par[tin[v]]=tout[v];
}

int res=0;
int n;
set<int>st;
void dfs(int v,int depth){
    int A=-1,B=-1;
    auto it=st.lower_bound(tin[v]);
    auto it1=it;

    if (it!=st.begin()) it1--;
    if (it!=st.end() && (*it)<=tout[v]){
        A=B=-1;

    } else if (it!=st.begin() && par[*it1]>=tin[v]){
        A=tin[v];
        B=(*it1);
        st.erase(it1);
        st.insert(tin[v]);

    } else {
        st.insert(tin[v]);
        A=tin[v];
    }
    res=max(res,(int)st.size());
    for (int to:g[v]){
        dfs(to,depth+1);
    }

    if (A!=-1) st.erase(A);
    if (B!=-1) st.insert(B);


}
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++){
        tt[i].clear();
        g[i].clear();
    }
    for (int i=2;i<=n;i++) {
        cin>>b[i];
        g[b[i]].push_back(i);
    }
    for (int i=2;i<=n;i++) {
        cin>>a[i];
        tt[a[i]].push_back(i);
    }


    timer=0;
    res=0;
    dfs1(1);
    dfs(1,1);
//    T1.roll_back({0,0});
//    T2.roll_back({0,0});
    cout<<res<<endl;



}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
6
1 2 3 4 5
1 2 2 3 4

2 3 4 5 6
**/