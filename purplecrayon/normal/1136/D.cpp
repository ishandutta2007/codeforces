#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    //let's fix x pupils to cross over to here (all of them must be able to swap with her)
    //the order of pupils doesn't actually matter (unless they can't cross eachother)
    //  this means it's always optimal for them to go from right to left order
    //this one must be able to cross everything in there except for the other pupils in front of him
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto& it : a) cin >> it, --it;
    vector<int> loc(n);
    for (int i = 0; i < n; i++) loc[a[i]] = i;

    vector<set<int>> adj(n);
    vector<vector<int>> badj(n);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b; 
        if (loc[a] > loc[b]) continue; 
        assert(loc[a] < loc[b]); 
        adj[a].insert(b), badj[b].push_back(a);
    }
    const int ROOT = a[n-1]; assert(loc[ROOT] == n-1);
    vector<int> imp = badj[ROOT];
    sort(imp.begin(), imp.end(), [&](int i, int j){
        return loc[i] > loc[j];
    });

    cerr << '\n';
    //use some prefix of imp
    int ans=0, er=0;
    for (int i = 0; i < sz(imp); i++){
        int n_need = n-1-loc[imp[i]]-er; //n_need to move
        assert(0 < n_need && n_need < n);
        bool bad = sz(adj[imp[i]]) < n_need;

        if (!bad) {
            ans++; er++;
            for (auto& it : badj[imp[i]]) adj[it].erase(imp[i]);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}