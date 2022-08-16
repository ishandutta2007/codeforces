#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1.3e5+10, MOD = 1e9+7;

struct DSU {
	vector<int> p, sz;
    int cc=0;
	void init(int n){ p.resize(n); sz.assign(n, 1); iota(p.begin(), p.end(), 0); cc=n; }
	int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
	bool union_sets(int a, int b){
		if ((a=find_set(a))==(b=find_set(b))) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b]=a, sz[a]+=sz[b], sz[b]=0;
        cc--;
		return true;
	}
} d;
int n, m;
string s, t;
bitset<MAXN> bs[6][6], have[6];


void solve(){
    cin >> s >> t;
    n = sz(s), m = sz(t);
    for (int i = 0; i < n; i++) {
        have[s[i]-'a'][i] = 1;
    }
    for (int i = 0; i < m; i++) {
        const int cur = t[i]-'a';
        for (int j = 0; j < 6; j++) if (j != t[i]-'a') {
            bs[cur][j] |= have[j];
        }
        for (int j = 0; j < 6; j++) have[j] >>= 1;
    }
    for (int p = 0; p+m <= n; p++) {
        d.init(6);
        for (int i = 0; i < 6; i++) for (int j = 0; j < 6; j++) {
            if (bs[i][j][p] || bs[j][i][p]) {
                d.union_sets(i, j);
            }
        }
        cout << 6-d.cc << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}