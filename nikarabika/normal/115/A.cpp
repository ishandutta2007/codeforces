#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 2e3 + 10;
vector <int> v[maxn];
bool mark[maxn];
int par[maxn], h[maxn];
int ans;

void dfs(int x){
    mark[x] = true;
    if(par[x] != -1)
        h[x] = h[par[x]] + 1;
    else
        h[x] = 1;
    if(h[x] > ans)
        ans = h[x];
    rep(i, v[x].size()){
        int child = v[x][i];
        if(!mark[child])
            dfs(child);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    reu(i, 1, n){
        int x;
        cin >> x;
        par[i] = x;
        if(x == -1)
            continue;
        v[x].pb(i);
        v[i].pb(x);
    }
    reu(i, 1, n)
        if(par[i] == -1)
            dfs(i);
    cout << ans << endl;
    return 0;
}