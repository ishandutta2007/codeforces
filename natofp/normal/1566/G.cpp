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


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;

const int nax = 1e5 + 5;
set<pii> costs[nax];
ll sumCheapest[nax];
multiset<ll> cheapestTriplets;
int n, m;
ordered_set weights[nax];
ordered_set allWeights;

void ini(){
    for(int i=1;i<=n;i++){
        sumCheapest[i] = 1e18;
        cheapestTriplets.insert(sumCheapest[i]);
    }
}

void recalc3(int v){
    ll now = sumCheapest[v];
    cheapestTriplets.erase(cheapestTriplets.find(now));
    if(costs[v].size() < 3){
        sumCheapest[v] = 1e18;
    }
    else{
        ll sum = 0;
        int c = 0;
        auto it = costs[v].begin();
        while(c < 3){
            sum += (*it).st;
            it++;
            c++;
        }
        sumCheapest[v] = sum;
    }
    cheapestTriplets.insert(sumCheapest[v]);
}

map<pii, int> wei;
set<pair<int, pii> > edges;
map<pii, int> whenAdded;

int timer = 0;

void add(int u, int v, int w){
    ++timer;
    if(u > v) swap(u, v);
    edges.insert(mp(w, mp(u, v)));
    whenAdded[mp(u, v)] = timer;
    pii cur = mp(u, v);
    wei[cur] = w;
    costs[u].insert(mp(w, v));
    costs[v].insert(mp(w, u));
    recalc3(u); recalc3(v);
    weights[u].insert(mp(w, v));
    weights[v].insert(mp(w, u));
    allWeights.insert(mp(w, timer));
}

void del(int u, int v, int w){
    costs[u].erase(mp(w, v));
    costs[v].erase(mp(w, u));
    if(u > v) swap(u, v);
    edges.erase(edges.find(mp(w, mp(u, v))));
    recalc3(u); recalc3(v);
    weights[u].erase(mp(w, v));
    weights[v].erase(mp(w, u));
    allWeights.erase(mp(w, whenAdded[mp(u, v)]));
}

ll bestDisjoint(){
    int x = (*edges.begin()).nd.st;
    int y = (*edges.begin()).nd.nd;
    ll ans = 1e18;
    int c = 0;
    auto it = (costs[x].begin());
    while(c < 4 && it != costs[x].end()){
        pii cur = (*it);
        c++;
        it++;
        if(cur.nd == y) continue;
        auto it2 = costs[y].begin();
        int ctr2 = 0;
        while(ctr2 < 5 && it2 != costs[y].end()){
            pii cur2 = (*it2);
            it2++;
            ctr2++;
            if(cur2.nd == x) continue;
            if(cur2.nd != cur.nd) ans = min(ans, (ll)cur.st + cur2.st);
        }
    }
    return ans;
}

ll outside(int LEQ, int x, int y){
    ll all = allWeights.order_of_key(mp(LEQ, 1e9));
    ll xA = weights[x].order_of_key(mp(LEQ, 1e9));
    ll yA = weights[y].order_of_key(mp(LEQ, 1e9));
    return (all + 1 - xA - yA);
}

ll cheapestOne(){
    int x = (*edges.begin()).nd.st;
    int y = (*edges.begin()).nd.nd;
    ll lo = (*edges.begin()).st - 1;
    ll hi = 1e9;
    ll ou = outside(2e9, x, y);
    if(ou == 0) return 1e18;
    while(lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        ll ou = outside(mid, x, y);
        if(ou > 0) hi = mid - 1;
        else lo = mid;
    }
    ll ac = lo;
    if(outside(hi, x, y) == 0) ac = hi;
    return ac + 1;
}

void que(){
    ll ans = (*cheapestTriplets.begin());
    ans = min(ans, bestDisjoint());
    ans = min(ans, (ll)(*edges.begin()).st + cheapestOne());
    cout << ans << "\n";
}

void solve(){
    cin >> n >> m;
    ini();
    for(int i=1;i<=m;i++){
        int x, y, w; cin >> x >> y >> w;
        add(x, y, w);
    }
    que();
    int q; cin >> q;
    while(q--){
        int ope; cin >> ope;
        if(ope == 0){
            int x, y; cin >> x >> y;
            pii cur = mp(min(x, y), max(x, y));
            del(x, y, wei[cur]);
        }
        else{
            int x, y, w; cin >> x >> y >> w;
            add(x, y, w);
        }
        que();
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}