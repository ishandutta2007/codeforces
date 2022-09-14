#pragma GCC optimize("Ofast")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=1000510;
const int inf=1e9;
const ll mod=1000000007;
vector<int>g[N];
vector<int>rg[N];
int cut[N];
int ans[N];
void solve(int Case){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    for (int i=1;i<=n;i++) cut[i]=g[i].size();
    set<pair<int,int> >st;
    for (int i=1;i<=n;i++){
        ans[i]=inf;
        if (i==n) ans[i]=0;
        st.insert({ans[i],i});
    }
    while (!st.empty()){
        int v=(*st.begin()).second;
        st.erase(st.begin());
        for (int to:rg[v]){
            cut[to]--;
            if (ans[to]>ans[v]+cut[to]+1){
                st.erase({ans[to],to});
                ans[to]=ans[v]+cut[to]+1;
                st.insert({ans[to],to});
            }
        }
    }
    cout<<ans[1]<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
5 10
ABAAA


1000000000

100000000
0 1
1 0 1 0 1 0 1 0 1 0 0 0
9 2 1 4 3 6 5 8 7 10 11 12

C(n-1,(n-1)/2)
 1 1 2 3 6 10 20 35 70 12
dp[i] = (i%2==1 ? dp[i-1]*2 : (dp[i-1]/4)*3);
**/