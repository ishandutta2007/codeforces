#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 24, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct FT {
	vector<ll> s;
	void init(int n){ s.assign(n, 0); }
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	void upd(int l, int r, ll v){ update(l, v), update(r+1, -v); }
	ll qry(int pos){ return query(pos+1); }
} ft[2];

int n, m, arr[MAXN], st[MAXN], en[MAXN], depth[MAXN], tt=0;
vector<int> adj[MAXN];

void dfs(int c=0, int p=-1, int d=0){
    st[c] = tt++; depth[c] = d;
    for (auto nxt : adj[c]) if (nxt != p) dfs(nxt, c, d+1);
    en[c] = tt-1;
}
ll qry(int a){
    return arr[a] + ft[depth[a]&1].qry(st[a]) - ft[(depth[a]&1)^1].qry(st[a]);
}
void pr(){
    for (int i = 0; i < n; i++) cout << qry(i) << ' ';
    cout << '\n';
}
void solve(){
    fsc(n), fsc(m);
    for (int i = 0; i < n; i++) fsc(arr[i]);
    for (int i = 0; i < n-1; i++){
        int a, b; fsc(a), fsc(b), --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs(); ft[0].init(n), ft[1].init(n);
    // for (int i = 0; i < n; i++) cout << st[i] << ' ' << en[i] << '\n';
    // cout << '\n';
    // pr();
    while (m--){
        int t; fsc(t);
        if (t == 1){ //upd
            int a, v; fsc(a), fsc(v); --a;
            ft[depth[a]&1].upd(st[a], en[a], v);
            // pr();
        } else if (t == 2) { //qry
            int a; fsc(a); --a;
            cout << qry(a) << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}