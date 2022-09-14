//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
//#define int ll
#define endl '\n'
const int N=1000010;
const ll mod=1000000007;
vector<pair<int,int> >g[N];
int cnt1=0;
int cnt2=0;
int used[N];
bool BAD=false;
void dfs(int v){
    for (auto cur:g[v]){
        int to=cur.first;
        int w=cur.second;
        if (used[to]==(used[v]^w^3)){
//            cout<<v<<" "<<to<<" "<<used[to]<<" "<<used[v]<<endl;
            BAD=true;
        } else if (!used[to]){
            used[to]=(used[v]^w);
            if (used[to]==1) cnt1++;
            else cnt2++;
            dfs(to);
        }
    }
}
void solve(){
    int n,m;cin>>n>>m;
    BAD=false;
    for (int i=1;i<=n;i++){
        used[i]=0;
        g[i].clear();
    }
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        string s;cin>>s;
        g[a].push_back({b,(s=="imposter")*3});
        g[b].push_back({a,(s=="imposter")*3});
    }
    int res=0;
    for (int i=1;i<=n;i++){
        if (!used[i]){
            used[i]=1;
            cnt1=1;
            cnt2=0;
            dfs(i);
            res+=max(cnt1,cnt2);
        }
    }
    if (BAD) cout<<-1<<endl;
    else cout<<res<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}