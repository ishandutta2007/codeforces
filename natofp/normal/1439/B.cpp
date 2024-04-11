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

const int nax = 1e5 + 5;
unordered_set<int> adj[nax];
int n, m, k;
set<pii> s;

void kill(int v){
    for(int x : adj[v]){
        int curSz = adj[x].size();
        s.erase(mp(curSz, x));
        s.insert(mp(curSz - 1, x));
        adj[x].erase(v);
    }
    int w = adj[v].size();
    s.erase(mp(w, v));
    adj[v].clear();
}

void solve(){
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=m;i++){
        int x, y; cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    int SQRT = 450;
    if(k > SQRT){
        cout << -1 << "\n";
        return;
    }
    s.clear();
    for(int i=1;i<=n;i++){
        s.insert(mp(adj[i].size(), i));
    }
    while(s.size()){
        pii cur = (*s.begin());
        if(cur.st < k - 1) kill(cur.nd);
        else break;
    }
    while(s.size()){
        pii cur = (*s.begin());
        if(cur.st >= k){
            cout << 1 << " " << s.size() << "\n";
            for(pii cur : s) cout << cur.nd << " ";
            cout << "\n";
            return;
        }
        else if(cur.st < k - 1){
            kill(cur.nd);
        }
        else{
            vector<int> who;
            for(int x : adj[cur.nd]) who.pb(x);
            who.pb(cur.nd);
            bool ok = true;
            for(int i=0;i<who.size();i++){
                int w = who[i];
                for(int j=i+1;j<who.size();j++){
                    if(!adj[w].count(who[j])) ok = false;
                }
            }
            if(ok){
                cout << 2 << "\n";
                for(int x : who) cout << x << " ";
                cout << "\n";
                return;
            }
            else kill(cur.nd);
        }
    }
    cout << -1 << "\n";


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}