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
#define mt make_tuple

using namespace std;

const int nax = 105;
int n;

bool eq[nax][nax][nax];

vector<int> adj[nax];
set<pii> es;
void dodaj(int x, int y){
    adj[x].pb(y);
    adj[y].pb(x);
    es.insert(mp(min(x, y), max(x, y)));
}

bool done[nax];
bool ok;

int dist[nax][nax];
bool vis[nax];

void gogo(){
    for(int i=1;i<=n;i++){
        fill(vis + 1, vis + n + 1, false);
        vector<int> Q;
        Q.pb(i);
        vis[i] = true;
        int wsk = 0;
        while(wsk < (int)Q.size()){
            int cur = Q[wsk++];
            for(int x : adj[cur]){
                if(!vis[x]){
                    vis[x] = true;
                    dist[i][x] = dist[i][cur] + 1;
                    Q.pb(x);
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=n;k++){
                bool s1 = (eq[i][j][k]);
                bool s2 = (dist[i][k] == dist[j][k]);
                if(s1 != s2) return;
            }
        }
    }
    ok = true;
}


void solve(){
    ok = false;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                eq[i][j][k] = false;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            string s; cin >> s;
            for(int k=1;k<=n;k++){
                if(s[k - 1] == '0'){
                    eq[i][j][k] = false;
                    eq[j][i][k] = false;
                }
                else{
                    eq[i][j][k] = true;
                    eq[j][i][k] = true;
                }
            }
        }
    }

    for(int s=2;s<=n;s++){
        es.clear();
        for(int i=1;i<=n;i++) adj[i].clear();
        fill(done + 1, done + n + 1, false);
        dodaj(1, s);
        vector<int> Q;
        Q.pb(1); Q.pb(s);
        done[1] = done[s] = true;
        int wsk = 0;
        while(wsk < Q.size()){
            int cur = Q[wsk++];
            int blisko = -1;
            for(int k=1;k<=n;k++){
                if(es.count(mp(min(cur, k), max(cur, k)))) blisko = k;
            }
            for(int i=1;i<=n;i++){
                if(!done[i] && eq[i][blisko][cur]){
                    done[i] = true;
                    Q.pb(i);

                    dodaj(cur, i);
                }
            }
        }
        int cnt = 0;
        for(int i=1;i<=n;i++) cnt += adj[i].size();
        if(cnt != (n - 1) * 2) continue;

        /*cout << "XD" << endl;
        for(int i=1;i<=n;i++){
            for(int j : adj[i]){
                if(j >= i) cout << i << " " << j << endl;
            }
        }

        cout << "XD" << endl;*/

        gogo();
        if(ok) break;
    }

    if(!ok) cout << "No" << "\n";
    else{
        cout << "Yes" << "\n";
        for(int i=1;i<=n;i++){
            for(int j : adj[i]){
                if(j > i) cout << i << " " << j << "\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}