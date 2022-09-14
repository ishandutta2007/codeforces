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
//#define endl '\n'
const int N=1000010;
const ll mod=998244353;
const ll inf=2000000000000000000;
vector<int>g[N];
vector<pair<int,int> >order;
void dfs(int v,int pr){
    if (pr) order.push_back({pr,v});
    for (int to:g[v]){
        if (to!=pr){
            dfs(to,v);
        }
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout<<"? "<<n<<" ";
    for (int i=1;i<=n;i++) cout<<i<<" ";
    cout<<endl;
    int MX;cin>>MX;
    int l=0,r=order.size();
    while (r-l>1){
        int mid=(l+r)/2;
        set<int>st;
        for (int i=l;i<mid;i++){
            st.insert(order[i].first);
            st.insert(order[i].second);
        }
        cout<<"? "<<st.size()<<" ";
        for (int v:st) cout<<v<<" ";
        cout<<endl;
        int cur;cin>>cur;
        if (cur==MX) r=mid;
        else l=mid;
    }
    cout<<"! "<<order[l].first<<" "<<order[l].second<<endl;


//    cout<<ans1<<endl;
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