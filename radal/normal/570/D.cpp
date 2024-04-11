#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N = 5e5+20,mod = 1e9+7,inf=1e9,maxm = 1e6+1;
vector<int> pre[N][26],adj[N];
int par[N],h[N],tin[N],T,tout[N];
string s;
void dfs(int v){
    tin[v] = T;
    T++;
    int d = (s[v-1]-'a');
    pre[h[v]][d].pb(tin[v]);
    for (int u : adj[v])
        if (u != par[v])
            dfs(u);
    tout[v] = T;
    T++;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    h[1] = 1; 
    adj[1].reserve(5000);
    adj[2].reserve(5000);
    adj[5].reserve(5000);
    pre[1000][0].reserve(1000);
    pre[3000][1].reserve(1000);
    rep(i,2,n+1){
        int p;
        cin >> p;
        h[i] = h[p]+1;
        par[i] = p;
        adj[p].pb(i);
    }
    cin >> s;
    dfs(1);
    while (q--){
        int v,x;
        cin >> v >> x;
        int f = 0;
        rep(i,0,26){
            int ind = lower_bound(pre[x][i].begin(),pre[x][i].end(),tin[v])-pre[x][i].begin();
            int sz = pre[x][i].size();
            if (ind >= sz || pre[x][i][ind] < tin[v]) continue;
            int ind2 = lower_bound(pre[x][i].begin(),pre[x][i].end(),tout[v])-pre[x][i].begin();
            if((ind2-ind)&1) f++;
            if (f > 1) break;
        }
        if (f > 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}