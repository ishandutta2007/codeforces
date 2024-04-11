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

const int nax = 1005;
bool adj[nax][nax];
int a[nax][nax];
int n;
bool ok[nax];
const int mod = 998244353;
int cnt[nax][nax];
bool vis[nax];
int color[nax];

void dfs(int v, int c){
    vis[v] = true;
    color[v] = c;
    for(int i=1;i<=n*2;i++){
        int x = i;
        if(ok[x] && adj[v][x] && vis[x] == false) dfs(x, 1 - c);
    }
}

void solve(){
    cin >> n;
    fill(vis, vis + n * 2 + 1, false);
    for(int i=1;i<=n*2;i++){
        for(int j=1;j<=n;j++) cin >> a[i][j];
    }
    for(int i=1;i<=n*2;i++){
        for(int j=1;j<=n*2;j++) adj[i][j] = false;
    }
    for(int i=1;i<=n*2;i++) ok[i] = true;
    for(int i=1;i<=n*2;i++){
        for(int j=i+1;j<=n*2;j++){
            int match = 0;
            for(int k=1;k<=n;k++){
                match |= (a[i][k] == a[j][k]);
            }
            if(match){
                adj[i][j] = true;
                adj[j][i] = true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cnt[i][j] = 0;
        }
    }
    for(int i=1;i<=n*2;i++){
        for(int j=1;j<=n;j++){
            cnt[j][a[i][j]] += 1;
        }
    }
    vector<int> must;
    while(1){
        int col = -1;
        int val = -1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cnt[i][j] == 1){
                    col = i;
                    val = j;
                    break;
                }
            }
        }
        if(col == -1) break;
        int id = -1;
        for(int i=1;i<=n*2;i++){
            if(ok[i]){
                if(a[i][col] == val) id = i;
            }
        }
        must.pb(id);
        ok[id] = false;
        vector<int> goAway;
        for(int i=1;i<=n*2;i++){
            if(ok[i] && adj[id][i]) goAway.pb(i);
        }
        for(int i=1;i<=n;i++){
            cnt[i][a[id][i]] -= 1;
        }
        for(int id : goAway){
            ok[id] = false;
            for(int i=1;i<=n;i++){
                cnt[i][a[id][i]] -= 1;
            }
        }
    }
    int cnt = 1;
    for(int i=1;i<=n*2;i++){
        if(ok[i] && vis[i] == false){
            cnt *= 2;
            cnt %= mod;
            dfs(i, 0);
        }
    }
    for(int i=1;i<=n*2;i++){
        if(ok[i] && color[i] == 0) must.pb(i);
    }
    cout << cnt << "\n";
    for(int x : must) cout << x << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}