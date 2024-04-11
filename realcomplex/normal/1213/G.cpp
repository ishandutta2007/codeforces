#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);

const int N = (int)2e5 + 9;
ll ans[N];
vector<pii>E[N];

int sz[N];
int pi[N];
ll total = 0;

int fin(int x){
    if(x == pi[x])
        return x;
    return pi[x]=fin(pi[x]);
}

void unite(int a, int b){
    a = fin(a);
    b = fin(b);
    if(sz[a]>sz[b])
        swap(a,b);
    total += sz[a] * 1ll * sz[b];
    pi[a]=b;
    sz[b] += sz[a];
}

int main(){
    fastIO;
    for(int i = 1; i < N; i ++ )
        sz[i] = 1, pi[i] = i;
    int n, q;
    cin >> n >> q;
    int u, v, w;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v >> w;
        E[w].push_back(mp(u,v));
    }
    for(int i = 1; i < N; i ++ ){
        for(auto x : E[i]){
            unite(x.fi, x.se);
        }
        ans[i] = total;
    }
    int a;
    for(int i = 0 ; i < q; i ++ ){
        cin >> a;
        cout << ans[a] << " ";
    }
    return 0;
}