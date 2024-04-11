#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

int n, m;
vector<int> e[500010];
int tp[500010];

bitset<500010> vis;

int main()
{
	cppio();
	cin >> n >> m;
	rrep(i, m) { int a, b; cin >> a >> b; e[a].pb(b); e[b].pb(a); }
	rrep(i, n) cin >> tp[i];

	static int idx[500010];
	iota(idx+1, idx+n+1, 1);
	sort(idx+1, idx+n+1, [&](const int& a, const int& b){ return tp[a] < tp[b]; });
	rrep(i_, n) {
		int i = idx[i_];
		static vector<int> tmp; tmp.clear();
		for(int j:e[i]) if (vis[j]) tmp.pb(tp[j]);
		sort(all(tmp));
		tmp.erase(unique(all(tmp)), tmp.end());
		int mex=1;
		while(mex<=sz(tmp) && tmp[mex-1]==mex) ++mex;
		if (mex != tp[i]) {
			cout << "-1\n"; return 0;
		}
		vis[i]=1;
	}
	rrep(i, n) cout << idx[i] << (i==n?'\n':' ');
	return 0;
}