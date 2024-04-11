/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "tayto.inp"
#define FILE_OUT "tayto.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
 
const int maxn=205;
 
set<int> s[maxn];
vector<pair<int,int> >ans;
int n,m;
 
void dfs(int x){
    while(s[x].size()){
        int p=*s[x].begin();
        s[x].erase(p);s[p].erase(x);
        ans.push_back(make_pair(x,p));
        dfs(p);
    }
}
 
int main(){
    fio;
    int T;cin>>T;
    while(T--){
        ans.clear();
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            s[x].insert(y);
            s[y].insert(x);
        }
        for(int i=1;i<=n;i++){
            if(s[i].size()%2==1){
                s[n+1].insert(i);s[i].insert(n+1);
            }
        }
        cout<<n-s[n+1].size()<<endl;
        for(int i=1;i<=n;i++) dfs(i);
        for(int i=0;i<ans.size();i++){
            if(ans[i].first!=n+1&&ans[i].second!=n+1){
                cout<<ans[i].first<<" "<<ans[i].second<<endl;
            }
        }
    }
}