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
vi dp1, dp2;
int ans = 0;
void dfs(int cur, int p=-1){
    int a1=0, b1=0, a2=0, b2 = 0;
    for(auto nei:g[cur]) if (nei!=p){
        dfs(nei, cur);
        int v1 = dp1[nei], v2 = dp2[nei];
        if (v1 > a1) b1 = a1, a1 = v1;
        else if (v1>b1) b1 = v1;
        if (v2 > a2) b2 = a2, a2 = v2;
        else if (v2>b2) b2 = v2;
    }
    int deg = g[cur].size(), down = deg;
    if (p!=-1) down--;
    dp1[cur] = max(down, max(a1,a2) + down - 1);
    dp2[cur] = 1 + a1;
    chkmax(ans, deg);
    chkmax(ans, dp1[cur]); 
    chkmax(ans, dp2[cur]);
    chkmax(ans, 1 + a1 + b1);
    //chkmax(ans, deg - 2  + 1 + a1 + b1);
    chkmax(ans, deg - 1 + max(a1,a2));
    //cout<<"CUR: "<<cur<<" "<<1<<" "<<a2<<" "<<b2<<endl;
    chkmax(ans, deg - 2 + a1 + b1);
    chkmax(ans, deg - 2 + a2 + b2);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n; g = vvi(n);
    loop(i,0,n-1){
    	int a,b; cin>>a>>b; a--; b--;
    	g[a].pb(b); g[b].pb(a);
    }
    dp2 = dp1 = vi(n); 
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
6
1 3
2 3
3 4
4 5
4 6



*/