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

int n, m;
set<pii> s;
int q;

void solve(){
    cin >> n >> m;
    cin >> q;
    for(int i=1;i<=q;i++){
        int a, b; cin >> a >> b;
        s.insert(mp(a, b));
    }
    vector<pii> cur;
    vector<pii> nxt;
    cur.pb(mp(1, 1));
    int iter = 0;
    while(true){
        iter += 1;
        nxt.clear();
        for(pii akt : cur){
            int mx = akt.st + akt.nd + (s.count(akt) > 0);
            int M = min(m, mx);
            int N = min(n, mx);
            nxt.pb(mp(N, akt.nd));
            nxt.pb(mp(akt.st, M));
        }
        sort(nxt.begin(), nxt.end());
        reverse(nxt.begin(), nxt.end());
        cur.clear();
        int bestSec = -1e9;
        for(pii akt : nxt){
            if(akt.nd <= bestSec){
                continue;
            }
            cur.pb(akt);
            bestSec = akt.nd;
            if(akt.st == n && akt.nd == m){
                cout << iter << "\n";
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}