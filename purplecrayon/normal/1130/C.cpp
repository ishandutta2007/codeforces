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
const int MAXN = 5e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct DSU {
	vector<int> p, sz;
	void init(int n){ p.resize(n); sz.assign(n, 1); iota(p.begin(), p.end(), 0); }
	int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
	bool union_sets(int a, int b){
		if ((a=find_set(a))==(b=find_set(b))) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b]=a, sz[a]+=sz[b], sz[b]=0;
		return true;
	}
} d;

void solve(){
    int n; cin >> n; d.init(n*n);
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2, --r1, --c1, --r2, --c2;
    vector<string> g(n);
    for (int i = 0; i < n; i++){
        cin >> g[i]; assert(sz(g[i]) == n);
        for (int j = 0; j < n; j++) if (g[i][j] == '0') {
            for (int k = 2; k < 4; k++){
                int ni = i+hA[k], nj = j+kA[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                if (g[ni][nj] == '0')
                    d.union_sets(i*n+j, ni*n+nj);
            }
        }
    }

    auto cost = [&](int a, int b, int c, int d){
        return (a-c)*(a-c) + (b-d)*(b-d);
    };

    int ans=cost(r1, c1, r2, c2);
    if (d.find_set(r1*n+c1) == d.find_set(r2*n+c2)) ans = 0;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) for (int l = 0; l < n; l++){
            if (d.find_set(i*n+j) != d.find_set(r1*n+c1)) continue;
            if (d.find_set(k*n+l) != d.find_set(r2*n+c2)) continue;
            ans = min(ans, cost(i, j, k, l));
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