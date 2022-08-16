#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 3e5+10, MAXQ = 5e5+10+MAXM, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 9e18+10;

int n, m, q, a[MAXN], rp[MAXN], p[MAXN], sz[MAXQ], split[MAXQ], loc[MAXN], amt=0;
set<ar<int, 2>> ans[MAXN];
vector<int> ch[MAXN];
ar<int, 2> ed[MAXM], qs[MAXQ];
bool del[MAXN], used[MAXM];

int find_set(int v){ 
    return v==rp[v]?v:rp[v]=find_set(rp[v]);
}
int union_sets(int a, int b){
    // cout << a << ' ' << b << "\n";
    if ((a=find_set(a))==(b=find_set(b))) return -1;
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = a, sz[a] += sz[b]; rp[b] = a; sz[b]=0;
    return b;
}
void er(set<ar<int, 2>>& s, ar<int, 2> c){
    s.erase(c);
}
void dfs(int c, int os, int ns){
    if (!del[c]) er(ans[os], ar<int, 2>{a[c], c}), ans[ns].insert(ar<int, 2>{a[c], c});
    loc[c] = ns;
    for (auto nxt : ch[c]) dfs(nxt, os, ns);
}

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
}
void solve(){
    fsc(n), fsc(m), fsc(q);
    for (int i = 0; i < n; i++) fsc(a[i]);
    for (int i = 0; i < m; i++) fsc(ed[i][0]), fsc(ed[i][1]), ed[i][0]--, ed[i][1]--;
    memset(used, 0, sizeof(used));
    for (int i = 0; i < q; i++){
        ar<int, 2> c; fsc(c[0]), fsc(c[1]), --c[1];
        qs[i]=c; if (c[0] == 2) used[c[1]]=1;
    }
    for (int i = 0; i < m; i++) if (!used[i]) qs[q] = ar<int, 2>{2, i}, q++;
    //each unite operation corresponds to a vertex
    //query -> query operation for a subtree
    //multiset -> small to large splitting?
    iota(p, p+n, 0); fill(sz, sz+n, 1); iota(rp, rp+n, 0); memset(split, -1, sizeof(split)); 
    for (int i = q-1; i >= 0; i--) if (qs[i][0] == 2) split[i] = union_sets(ed[qs[i][1]][0], ed[qs[i][1]][1]);//, cout << ed[qs[i][1]][0] << ' ' << ed[qs[i][1]][1] << ' ' << split[i] << '\n'; 
    for (int i = 0; i < n; i++) {
        if (p[i] != i) ch[p[i]].push_back(i);
        loc[i] = find_set(i); ans[loc[i]].insert({a[i], i});
    }
    for (int i = 0; i < q; i++){
        auto c = qs[i];
        if (c[0] == 1){
            auto& cur = ans[loc[c[1]]];
            if (cur.empty()){ cout << "0\n"; continue; }
            auto cans=*cur.rbegin(); del[cans[1]]=1;
            cout << cans[0] << '\n'; er(cur, cans);
        } else {
            int v = split[i];
            if (v == -1 || v==loc[v]) continue;
            dfs(v, loc[v], v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}