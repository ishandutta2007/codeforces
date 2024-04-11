#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize()
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
vvi g;
vi col;
vector<set<int>> ans;
int main()
{
    boost;
    int n,m;cin>>n>>m;g.resize(n);ans.resize(100000+1);col.resize(n);
    FOR(i,0,n-1)cin>>col[i];
    FOR(i,1,m){
      int x,y,z;cin>>x>>y;--x,--y;
      g[x].pb(y);
      g[y].pb(x);
    }
    FOR(i,0,n-1){
      for(int j:g[i]){
         if(col[i]==col[j])continue;
         ans[col[j]].insert(col[i]);
      }
    }
    ii yo={0,-*min_element(all(col))};
    FOR(i,1,100000)if(sz(ans[i]))yo=max(yo,make_pair(sz(ans[i]),-i));
    cout<<-yo.S;
   return 0;
}