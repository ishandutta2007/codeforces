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
const int INF = 1e18;

int n;
vvii g;
vb e;
vi dp;
void dfs(int cur, int& cnt, int d=0, int fir=INF, int sec=INF){
    int me = cnt;
    chkmin(dp[cur], d + fir);
    if (e[cur]){
        cnt++;
        chkmin(dp[cur], me + sec);
    }
    sort(all(g[cur]));
    for(auto nei:g[cur]){
        dfs(nei.y, cnt, d+1, min(fir, dp[cur] - d), min(sec, dp[cur] - me + 1));
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    g.resize(n+1); e.resize(n+1,0);  dp.resize(n+1,INF); dp[0]=0;
    loop(i,0,n){
        char c; int p; cin>>p>>c;
        g[p].pb({c,i+1});
    }
    int k; cin>>k;
    vi a(k);
    loop(i,0,k){
        int x; cin>>x; e[x]=1;
        a[i]=x;
    }
    int cnt=0;
    dfs(0,cnt);
    loop(i,0,k) cout<<dp[a[i]]<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ g.cpp -o a & a
10
0 i
1 q
2 g
0 k
1 e
5 r
4 m
5 h
3 p
3 e
5
8 9 1 10 6



*/