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
const int MAXN = 5e3+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

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
int to_int(char c) {
    if (c >= 'A') return c-'A'+10;
    return c-'0';
}
void solve(){
    int n, m; cin >> n >> m;


    int ans=0;

    vector<int> prv(m, -1);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        vector<bool> a(m);
        for (int i = 0; i < sz(s); i++) {
            int cur=to_int(s[i]);
            for (int j = 0; j < 4; j++) {
                a[4*i+j] = (cur>>(3-j))&1;
            }
        }

        vector<int> lead(m, -1);
        d.init(2*m);
        for (int j = 0; j < m; j++) {
            if (prv[j] != -1 && lead[prv[j]] != -1) d.union_sets(lead[prv[j]], j);
            if (j && a[j] && a[j-1]) d.union_sets(m+j-1, m+j);
            if (prv[j] != -1 && a[j]) d.union_sets(j, m+j);

            if (prv[j] != -1)
                lead[prv[j]] = j;
        }
        int cc=0;
        vector<int> cur(2*m, -1);
        for (int j = 0; j < m; j++) {
            if (a[j] && cur[d.find_set(m+j)] == -1) {
                cur[d.find_set(m+j)] = cc++;
            }
        }
        for (int j = 0; j < m; j++) if (prv[j] != -1 && cur[d.find_set(j)] == -1) {
            ans++;

            cur[d.find_set(j)]--;
        }

        for (int j = 0; j < m; j++)
            prv[j] = max(-1, cur[d.find_set(j+m)]);

        //for (auto c : a) cerr << c; cerr << endl;
        //for (auto c : prv) cerr << c << ' '; cerr << endl;
        //cerr << "ans: " << ans << endl;
    }
    set<int> s;
    for (int i = 0; i < m; i++) if (prv[i] != -1)
        s.insert(prv[i]);

    cout << ans+sz(s) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}