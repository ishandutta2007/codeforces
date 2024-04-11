#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;

int n;
vvi g;
vi val;
int dfs(int cur=0, int p=-1, int d=0){
    val[cur] = d;
    int sz = 1;
    for(auto nei:g[cur]) if (nei!=p){
        sz+=dfs(nei, cur, d+1);
    }
    val[cur] -= (sz-1);
    return sz;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int k; cin>>n>>k; g = vvi(n);
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    val = vi(n);
    dfs(0);
    sort(all(val)); reverse(all(val));
    int ans=0;
    loop(i,0,k) ans+=val[i];
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a


*/