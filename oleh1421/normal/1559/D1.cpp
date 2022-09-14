#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define endl '\n'
const int N=400010;
const ll mod=1000000007;
struct DSU{
    int par[N];
    int get(int x){
        if (x==par[x]) return x;
        return par[x]=get(par[x]);
    }
    bool can(int a,int b){
        a=get(a);
        b=get(b);
        return (a!=b);
    }
    void unite(int a,int b){
        a=get(a);
        b=get(b);
        par[a]=b;
    }
};
DSU T[2];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=0;j<2;j++){
            T[j].par[i]=i;
        }
    }
    int m1,m2;cin>>m1>>m2;
    for (int i=1;i<=m1;i++){
        int a,b;cin>>a>>b;
        T[0].unite(a,b);
    }
    for (int i=1;i<=m2;i++){
        int a,b;cin>>a>>b;
        T[1].unite(a,b);
    }
    vector<pair<int,int> >ans;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (T[0].can(i,j) && T[1].can(i,j)){
                ans.push_back({i,j});
                T[0].unite(i,j);
                T[1].unite(i,j);
            }
        }
    }
    cout<<ans.size()<<endl;
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