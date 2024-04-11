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

const int nax = 2e5 + 5;
vector<int> adj[nax];
int n, m;
vector<int> rv[nax];
int outdeg[nax];
int wynik[nax];
const int inf = 1e9;
bool done[nax];

void solve(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        rv[y].pb(x);
        outdeg[x]++;
    }

    set<pii> opcje;
    opcje.insert(mp(0, n));
    for(int i=1;i<n;i++){
        wynik[i] = inf;
        opcje.insert(mp(wynik[i], i));
    }
    while(opcje.size()){
        pii cur = (*opcje.begin());
        opcje.erase(cur);
        int kto = cur.nd;
        done[kto] = true;
        for(int x : rv[kto]){
            if(done[x]) continue;
            outdeg[x]--;
            opcje.erase(mp(wynik[x], x));
            wynik[x] = min(wynik[x], outdeg[x] + wynik[kto] + 1);
            opcje.insert(mp(wynik[x], x));
        }
    }
    cout << wynik[1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}