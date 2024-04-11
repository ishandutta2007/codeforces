#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 5e5 + 5;
ll L[nax];
ll R[nax];
ll c[nax];
int n;

const int roz = (1 << 21);
pll tree[roz];
ll added[roz];

void add(int lo, int hi, int u, int a, int b, ll val){
    if(lo == a && b == hi){
        tree[u].st += val;
        added[u] += val;
        return;
    }
    if(b <= a) return;
    int mid = (lo + hi) / 2;
    add(lo, mid, u * 2, a, min(b,mid), val);
    add(mid, hi, u*2+1,max(a,mid),b,val);
    tree[u] = max(tree[u * 2], tree[u * 2 + 1]);
    tree[u].st += added[u];
}

pll ask(int lo, int hi, int u, int a, int b){
    if(lo == a && b == hi){
        return tree[u];
    }
    if(b <= a) return mp(-1e18, -1e18);
    int mid = (lo + hi) / 2;
    auto L = ask(lo, mid, u * 2, a, min(b, mid));
    auto R = ask(mid, hi, u * 2 + 1, max(a,mid) ,b);
    L = max(L, R);
    L.st += added[u];
    return L;
}

set<int> uni;
vector<int> g;
int get(int val){
    return (int)(lower_bound(g.begin(), g.end(), val) - g.begin());
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> L[i] >> R[i] >> c[i];
    for(int i=1;i<=n;i++){
        if(L[i] > R[i]) swap(L[i], R[i]);
        uni.insert(R[i]);
        uni.insert(L[i]);
    }
    for(int x : uni) g.pb(x);
    ll ans = -1e18;
    ll LO = 0, HI = 0;
    for(int i=roz/2;i<roz;i++) tree[i] = mp(-1e18, -1e18);
    for(int i=roz/2;i<roz/2+g.size();i++) tree[i] = mp(0, i-roz/2);
    for(int i=roz/2-1;i>=1;i--) tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    multiset<pair<pll, ll> > starts;
    for(int i=1;i<=n;i++){
        starts.insert(mp(mp(L[i], R[i]), c[i]));
    }
    auto it = (g.begin());
    for(int i=0;i<g.size();i++){
        ll cur = (*it);
        it++;
        add(0, roz/2, 1, i, i+1, -cur);
    }
    for(int i=1;i<=n;i++){
        ll p = get(R[i]);
        add(0, roz/2, 1, p, g.size(), c[i]);
    }
    vector<pair<pll, int> > s;
    for(int i=1;i<=n;i++){
        s.pb(mp(mp(L[i], R[i]), c[i]));
    }
    sort(s.begin(), s.end());
    for(auto x : s){
        ll start = x.st.st;
        while(starts.size()){
            auto cur = (*starts.begin());
            if(cur.st.st < start){
                starts.erase(starts.find(cur));
                ll p = get(cur.st.nd);
                add(0, roz/2, 1, p, g.size(), -cur.nd);
            }
            else break;
        }
        auto best = ask(0,roz/2,1,get(x.st.st), g.size());
        best.st += start;
        if(best.st >= ans){
            ans = best.st;
            HI = g[best.nd];
            LO = start;
        }
    }
    if(ans < 0){
        ans = 0;
        LO = 1e9 + 5;
        HI = 1e9 + 5;
    }
    cout << ans << "\n";
    cout << LO << " " << LO << " " << HI << " " << HI << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}