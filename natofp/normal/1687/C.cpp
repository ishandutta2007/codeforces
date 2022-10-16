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
ll a[nax];
ll b[nax];
ll c[nax];
ll pref[nax];
int n, m;
set<int> nonactive;

vector<int> kon[nax];
vector<int> pocz[nax];
set<pii> used;
vector<pii> toUse;

void chckpocz(int l){
    for(int r : pocz[l]){
        if(nonactive.count(r));
        else if(used.count(mp(l, r)) == 0){
            toUse.pb(mp(l, r));
            used.insert(mp(l, r));
        }
    }
}

void chckkon(int r){
    for(int l : kon[r]){
        if(nonactive.count(l));
        else if(used.count(mp(l, r)) == 0){
            toUse.pb(mp(l, r));
            used.insert(mp(l, r));
        }
    }
}

void solve(){
    used.clear();
    toUse.clear();
    nonactive.clear();
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) c[i] = a[i] - b[i];
    for(int i=1;i<=n;i++) pref[i] = pref[i - 1] + c[i];
    for(int i=0;i<=n;i++){
        pocz[i].clear();
        kon[i].clear();
    }
    for(int i=1;i<=m;i++){
        int l, r; cin >> l >> r;
        l--;
        pocz[l].pb(r);
        kon[r].pb(l);
    }
    for(int i=0;i<=n;i++) nonactive.insert(i);
    nonactive.insert(1e9);
    for(int i=0;i<=n;i++){
        if(pref[i] == 0){
            nonactive.erase(i);
            chckpocz(i);
            chckkon(i);
        }
    }
    int wsk = 0;
    while(wsk < toUse.size()){
        pii cur = toUse[wsk++];
        while(1){
            auto it = nonactive.lower_bound(cur.st);
            int ile = (*it);
            if(ile > cur.nd) break;
            nonactive.erase(ile);
            chckpocz(ile);
            chckkon(ile);
        }
    }
    if(nonactive.size() > 1) cout << "NO" << "\n";
    else cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}