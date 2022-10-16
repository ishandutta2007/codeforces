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

const int nax = 3e5 + 5;
int a[nax];
int n,m;

int pkt[nax];
vector<int> ans;
vector<int> pot;

vector<int> adj[nax];
bool vis[nax];

int cc = 0;
void dfs(int v){
    cc++;
    vis[v] = true;
    for(int x : adj[v]){
        if(vis[x] == false) dfs(x);
    }
}


bool ok(int shift){

    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++){
        int to = i - shift;
        if(to < 1) to += n;
        adj[a[i]].pb(to);
    }

    for(int i=1;i<=n;i++) vis[i] = false;
    int sum = 0;
    for(int i=1;i<=n;i++){
        if(vis[i] == false){
            cc = 0;
            dfs(i);
            sum += cc;
            sum--;
        }
    }
    return sum <= m;
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    fill(pkt, pkt + n, 0);
    for(int i=1;i<=n;i++){
        int kto = (i - a[i] + n) % n;
        pkt[kto]++;
    }
    ans.clear();
    pot.clear();
    for(int i=0;i<n;i++){
        if(pkt[i] >= n - m * 2) pot.pb(i);
    }
    for(int x : pot){
        if(ok(x)) ans.pb(x);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << " ";
    for(int x : ans) cout << x << " ";
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}