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

const int nax = 605;
int n, m;
vector<pii> to[nax];
int ans[nax][nax];
int d[nax];
bool vis[nax];

void calc(int start){
    for(int i=0;i<nax;i++){
        d[i] = 2e9;
        vis[i] = false;
    }
    d[start] = 0;
    for(int f=1;f<=n;f++){
        int id = -1;
        int best = 2e9;
        for(int i=1;i<=n;i++){
            if(!vis[i] && d[i] < best){
                best = d[i];
                id = i;
            }
        }
        vis[id] = true;
        for(pii go : to[id]){
            for(int w=0;w<2;w++){
                int target = (go.st + d[id] % n + w);
                while(target > n) target -= n;
                d[target] = min(d[target], d[id] + go.nd + w);
            }
        }
        if(id != start){
            int g = id + 1;
            if(g > n) g -= n;
            d[g] = min(d[g], d[id] + 1);
            g++;
            if(g > n) g -= n;
            d[g] = min(d[g], d[id] + 2);
        }

    }
    for(int i=1;i<=n;i++) ans[start][i] = d[i];
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b,c; cin >> a >> b >> c;
        a++, b++;
        to[a].pb(mp(b, c));
    }
    for(int i=1;i<=n;i++) calc(i);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout << ans[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}