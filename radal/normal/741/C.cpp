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
const long long int N=2e5+20,mod = 1e9+7,inf=1e9;
int p[N],col[N];
void dfs(int v,int c){
    col[v] = c;
    if (!col[p[v]]) dfs(p[v],3-c);
    if ((v&1) && !col[v+1]) dfs(v+1,3-c);
    if ((v&1) == 0 && !col[v-1]) dfs(v-1,3-c);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pll> ve;
    rep(i,0,n){
        int x,y;
        cin >> x >> y;
        p[x] = y;
        p[y] = x;
        ve.pb({x,y});
    }
    rep(i,1,2*n+1) if (!col[i]) dfs(i,1);
    for (pll u : ve) cout << col[u.X] << ' ' << col[u.Y] << endl;
    return 0;
}