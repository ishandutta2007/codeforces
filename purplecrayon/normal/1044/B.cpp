#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e3+10, MOD = 1e9+7;

int depth[MAXN];
vector<int> adj[MAXN];

void init_lca(int c=0, int p=-1, int d=0){
	depth[c]=d;
	for (auto nxt : adj[c]) if (nxt != p) init_lca(nxt, c, d+1);
}
int qry(char c, int a) {
    cout << c << ' ' << a+1 << endl;
    int x; cin >> x, --x;
    return x;
}
int global = 0;
int cur_test = 0;
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    int k1; cin >> k1;
    vector<int> a(k1); for (auto& c : a) cin >> c, --c;
    int k2; cin >> k2;
    vector<int> b(k2); for (auto& c : b) cin >> c, --c;

    int ROOT = qry('B', b[0]);

    init_lca(ROOT, -1, 0);

    sort(a.begin(), a.end(), [&](int i, int j){ return depth[i] < depth[j]; });

    int need = qry('A', a[0]);
    for (auto c : b) if (need == c){ cout << "C " << a[0]+1 << endl; return; }
    cout << "C -1" << endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T; global = T;
    while (T--) { cur_test++; solve(); }
}