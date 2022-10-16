#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int deg[N];
int ans[N];

void solve(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++){
        int k; cin >> k;
        deg[i] = k;
        while(k--){
            int x; cin >> x;
            adj[x].pb(i);
        }
    }
    vector<int> Q;
    for(int i=1;i<=n;i++){
        if(deg[i] == 0) Q.pb(i);
    }
    int w = 0;
    while(w < Q.size()){
        int cur = Q[w++];
        for(int to : adj[cur]){
            deg[to]--;
            if(deg[to] == 0) Q.pb(to);
        }
    }
    if(Q.size() != n){
        cout << -1 << "\n";
        return;
    }
    for(int i=1;i<=n;i++) ans[i] = 1;

    for(int i=1;i<=n;i++){
        int cur = Q[i - 1];
        for(int to : adj[cur]){
            ans[to] = max(ans[to], ans[cur] + (to < cur));
        }
    }
    int ac = 0;
    for(int i=1;i<=n;i++) ac = max(ac, ans[i]);
    cout << ac << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}