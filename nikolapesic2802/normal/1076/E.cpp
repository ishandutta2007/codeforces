#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
const int N=3*1e5+5;
vector<vector<int> > graf(N);
vector<vector<pair<int,int> > > add(N);
vector<int> depth(N);
void dfs(int tr,int par)
{
    for(auto p:graf[tr])
    {
        if(p==par)
            continue;
        depth[p]=depth[tr]+1;
        dfs(p,tr);
    }
}
vector<ll> sol(N);
vector<ll> sub(N);
void solve(int tr,int par,ll val)
{
    /*printf("Usao za %i:\n",tr);
    for(auto p:v)
    {
        printf("%i %i\n",p.first,p.second);
    }*/
    for(auto p:add[tr])
    {
        val+=(ll)p.second;
        sub[min(depth[tr]+p.first+1,N-1)]+=(ll)p.second;
    }
    val-=(ll)sub[depth[tr]];
    sol[tr]=val;
    for(auto p:graf[tr])
    {
        if(p==par)
            continue;
        solve(p,tr,val);
    }
    for(auto p:add[tr])
    {
        sub[min(depth[tr]+p.first+1,N-1)]-=(ll)p.second;
    }
}
int main()
{
    int n;
    scanf("%i",&n);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        graf[a].pb(b);
        graf[b].pb(a);
    }
    depth[0]=0;
    dfs(0,-1);
    int m;
    scanf("%i",&m);
    for(int i=0;i<m;i++)
    {
        int v,d,x;
        scanf("%i %i %i",&v,&d,&x);
        v--;
        add[v].pb({d,x});
    }
    ll val=0;
    solve(0,-1,val);
    for(int i=0;i<n;i++)
    {
        printf("%lld ",sol[i]);
    }
    return 0;
}