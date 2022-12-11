#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
const ll inf = (ll)1e18;
vector<int> T[N];
ll t[N];
ll h[N];

ll dp[N][2];
ll outp = inf;

void dfs(int u, int par, int ins){
    dp[u][0]=dp[u][1]=inf;
    int nx;
    ll sum = 0;
    vector<pii> ch;
    int fin = 0, fout = 0;
    for(auto x : T[u]){
        if(x == par) continue;
        if(h[u] == h[x]) nx = 3;
        else if(h[u] < h[x]) nx = 1;
        else nx = 2;
        dfs(x, u, nx);
        if(nx == 1){
            sum += dp[x][0]; // 0 -> outgoing
            fin ++ ;
        }
        else if(nx == 2){
            sum += dp[x][1]; // 1 -> ingoing
            fout ++ ;
        }
        else{
            sum += dp[x][0];
            ch.push_back(mp(dp[x][0], dp[x][1]));
        }
    }
    int m = ch.size();
    vector<ll> bb;
    for(auto x : ch)
        bb.push_back(x.se-x.fi);
    sort(bb.begin(), bb.end());
    ll best;
    ll nig = 1;
    int nin, nout;
    for(int i = 0 ; i <= m ; i ++ ){
        if(i)
            sum += bb[i-1];
        nin = fin + (m - i);
        nout = fout + i;
        if(ins == 0){
            outp = min(outp, sum + max(nin,nout) * 1ll * t[u]);
        }

        if(ins == 1 || ins == 3){
            dp[u][0] = min(dp[u][0], sum + max(nin,nout+1) * 1ll * t[u]);
        }
        if(ins == 2 || ins == 3){
            dp[u][1] = min(dp[u][1], sum + max(nin+1, nout) * 1ll * t[u]);
        }

    }

}

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ )
        cin >> t[i];
    for(int i = 1; i <= n; i ++ )
        cin >> h[i];
    int u, v;
    for(int i = 1; i < n ; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1, -1, 0);

    cout << outp << "\n";
    return 0;
}