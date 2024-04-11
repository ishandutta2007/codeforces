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

const int nax = 1e5 + 5;
int b[nax];
int n;

vector<int> pos[nax];

void solve(){
    vector<pii> es;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++){
        int from = i;
        int to = b[i];
        assert(from != to);
        if(from < to){
            es.pb(mp(from, to - 1));
        }
        else{
            es.pb(mp(to, from - 1));
        }
    }
    int mx = 0;
    int act = 0;
    vector<pii> ev;
    for(pii cur : es){
        ev.pb(mp(cur.st, 1));
        ev.pb(mp(cur.nd + 1, -1));
    }
    sort(ev.begin(), ev.end());
    int k = -1;
    for(pii cur : ev){
        act += cur.nd;
        if(act == n) k = cur.st;
    }
    cout << k << "\n";
    vector<int> ans;
    for(int i=1;i<=n;i++) pos[b[i]].pb(i);
    int done = 0;
    int value = 0;
    for(int i=1;i<=n;i++){
        if(b[i] == n + 1) value = n + 1;
    }
    while(done < n){
        vector<int> p = pos[value];
        done += p.size();
        int wazne = -1;
        for(int x : p){
            if(pos[x].size()) wazne = x;
        }
        for(int x : p){
            if(x != wazne) ans.pb(x);
        }
        if(wazne != -1) ans.pb(wazne);
        value = wazne;
    }
    for(int x : ans) cout << x << " ";
    cout << "\n";

    for(int i=1;i<=n;i++) pos[b[i]].clear();

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}