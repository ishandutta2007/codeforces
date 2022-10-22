#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define vb vector<bool>
#define x first
#define y second
#define loop(i,s,e) for(int i=s;i<e;++i)
#define loopr(i,s,e) for(int i=e;i>=s;--i)
#define pb push_back
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(a) a.begin(), a.end()
using namespace std;
const int INF = 1e9;

int n;
vvi g;

vi ans;
int res = 0;
void make(int a, int b){
    swap(ans[a], ans[b]);
    res+=2;
}
void recon(int cur, int f=-1){
    for(auto nei:g[cur]) if(nei!=f){
        recon(nei, cur);
    }
    if (ans[cur]==cur){
        if (f!=-1) make(cur, f);
        else{
            make(cur, g[cur][0]);
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    g.resize(n);
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    ans.resize(n);
    loop(i,0,n) ans[i]=i;
    recon(0);
    cout<<res<<endl;
    loop(i,0,n) cout<<ans[i]+1<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ bb.cpp -o a & a
5
1 2
2 3
2 4
4 5


3
1 2
2 3

*/