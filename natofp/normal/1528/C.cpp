#include <bits/stdc++.h>
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
int para[nax];
int parb[nax];
int n;

vector<int> sonsa[nax];
vector<int> sonsb[nax];

int pre[nax];
int pos[nax];
int timer = 0;

int ans = 0;

void calc(int v, int p){
    pre[v] = ++timer;
    for(int x : sonsb[v]){
        calc(x, v);
    }
    pos[v] = ++timer;
}

set<pii> cur;

pii val[nax];

void dfs(int v, int p){
    pii akt = val[v];
    vector<pii> wywal;
    vector<pii> dodaj;

    if(cur.size() == 0){
        wywal.pb(akt);
        cur.insert(akt);
    }
    else{
        auto it = cur.lower_bound(akt);
        // kiedy jest cos nad
        if(it != cur.begin()){
            it--;
            pii pop = (*it);
            if(pop.st < akt.st && pop.nd > akt.nd){
                dodaj.pb(pop);
                wywal.pb(akt);
                cur.insert(akt);
                cur.erase(pop);
            }
        }
        if(dodaj.size() == 0){
            // jestesmy na gorze, czy wyjebac kogos trzeba ?
            auto it = cur.lower_bound(akt);
            if(it != cur.end()){
                pii dol = (*it);
                if(dol.st > akt.st && dol.nd < akt.nd){
                    ; // zle
                }
                else{
                    wywal.pb(akt);
                    cur.insert(akt);
                }
            }
            else{
                wywal.pb(akt);
                cur.insert(akt);
            }
        }
    }

    if(sonsa[v].size() == 0){
        ans = max(ans, (int)cur.size());
    }
    for(int son : sonsa[v]){
        dfs(son, v);
    }

    for(pii x : wywal){
        cur.erase(x);
    }
    for(pii x : dodaj){
        cur.insert(x);
    }
    return;
}


void solve(){
    //cur.clear();
    ans = 0;
    timer = 0;
    cin >> n;
    for(int i=1;i<=n;i++){
        sonsa[i].clear();
        sonsb[i].clear();
    }
    for(int i=1;i<n;i++){
        cin >> para[i + 1];
        sonsa[para[i + 1]].pb(i + 1);
    }
    for(int i=1;i<n;i++){
        cin >> parb[i + 1];
        sonsb[parb[i + 1]].pb(i + 1);
    }
    calc(1, 1);
    for(int i=1;i<=n;i++) val[i] = mp(pre[i], pos[i]);
    dfs(1, 1);
    cout << ans << "\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();


    return 0;
}