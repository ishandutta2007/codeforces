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
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true
	TwoSat(int n = 0) : N(n), gr(2*n) {}
	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}
	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }
	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}
	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}
	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

int n, p, s, m;
void solve(){
    read(n, p, s, m); TwoSat g(p+s);
    for (int i = 0; i < n; i++){
        int a, b; read(a, b), --a, --b;
        g.either(a, b);
    }
    for (int i = 0; i < p; i++){
        int l, r; read(l, r), --l, --r;
        g.either(~i, l+p); if (r+1 < s) g.either(~i, ~(r+1+p));
    }
    for (int i = p+1; i < p+s; i++) g.either(i-1, ~i);
    for (int i = 0; i < m; i++){
        int a, b; read(a, b), --a, --b;
        g.atMostOne({a, b});
    }
    //if f(i-1) is false, f(i) should be false
    //either f(i-1) or ~f(i)
    bool good=g.solve();
    if (!good){ cout << "-1\n"; return; }
    vector<int> v;
    for (int i = 0; i < p; i++) if (g.values[i]) v.push_back(i);
    int f=-1;
    for (int i = p; i < p+s; i++) if (g.values[i]) f = i-p+1;
    assert(f != -1);
    cout << sz(v) << ' ' << f << '\n';
    for (auto it : v) cout << (it+1) << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}