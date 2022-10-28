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
const int MAXN = 3e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct DSU {
	vector<int> p;
	void init(int n){ p.resize(n); iota(p.begin(), p.end(), 0); }
	int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
	bool union_sets(int a, int b){
		if ((a=find_set(a))==(b=find_set(b))) return false;
		p[b]=a; return true;
	}
} d;

int n, k, a[MAXN], deg[MAXN], nxt[MAXN], loc[MAXN];
vector<int> adj[MAXN];

void solve(){
    cin >> n >> k; d.init(n);
    for (int i = 0; i < n; i++) cin >> a[i], --a[i];
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < k; i++){
        int a, b; cin >> a >> b, --a, --b;
        nxt[a] = b;
        if (!d.union_sets(a, b)){ cout << "0\n"; return; }
    }
    for (int i = 0; i < n; i++) if (d.p[i] == i){
        int l=0, c=i;
        while (c != -1) loc[c] = l++, c = nxt[c];
    }
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < n; i++) if (a[i] != -1){
        if (d.find_set(a[i]) == d.find_set(i)){
            if (loc[a[i]] >= loc[i]) { cout << "0\n"; return; }
            continue;
        } 
        adj[d.find_set(a[i])].push_back(d.find_set(i)), deg[d.find_set(i)]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) if (d.p[i] == i && !deg[i]) q.push(i);

    vector<int> top; top.reserve(n);

    while (sz(q)){
        auto c = q.front(); q.pop();
        top.push_back(c);
        for (auto nxt : adj[c]) if ((--deg[nxt]) == 0) q.push(nxt);
    }
    for (int i = 0; i < n; i++) if (deg[i]){ cout << "0\n"; return; }
    for (auto& it : top){
        int c=it;
        while (c != -1) cout << (c+1) << ' ', c = nxt[c];
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}