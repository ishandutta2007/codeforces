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

const int maxn = int(2e5) + 10;

int n;
int nxt[maxn];
int ans[maxn];
int ind[maxn];

vector<int> cycles[maxn]; int cn;

bool vis[maxn], instk[maxn];
bool done[maxn];

void dfs1(int x) {
	vis[x] = true;
	instk[x] = true;
	int y = nxt[x];
	if (!vis[y]) {
		dfs1(y);
	} else if (instk[y]) {
		++cn; auto &v = cycles[cn]; v.clear();
		for (int t=y;; t=nxt[t]) {
			v.pb(t);
			if (t == x) break;
		}
	}
	instk[x] = false;
}

void Work() {
	cin >> n; fill(ind+1, ind+n+1, 0);
	rrep(i, n) {
		cin >> nxt[i];
		++ind[nxt[i]];
	}

	cn = 0;

	fill(vis+1, vis+n+1, false);
	fill(done+1, done+n+1, false);
	fill(ans+1, ans+n+1, -1);

	rrep(i, n) if (!vis[i]) dfs1(i);
	rrep(ci, cn) { auto &v = cycles[ci];
		int s = v.size();
		rep(i, s) {
			int a = v[i], b = v[(i+1==s)?0:(i+1)];
			ans[a] = b;
			done[a] = true;
		}
	}

	static int solo[maxn], sn; sn = 0;
	rrep(i, n) if (ind[i] == 0) {
		if (done[nxt[i]]) solo[sn++] = i;
		else {
			for (int j=i;;) {
				if (done[nxt[j]]) {
					ans[j] = i;
					done[j] = true;
					break;
				}
				ans[j] = nxt[j];
				j = nxt[j];
				done[j] = true;
			}
		}
	}

	for (int i=(sn&1); i<sn; i+=2) {
		int a = solo[i], b = solo[i+1];
		done[a] = done[b] = true;
		ans[a] = b; ans[b] = a;
	}

	if (sn & 1) {
		int a = solo[0];
		int b = nxt[a];
		int t = b;
		for (; ans[t]!=b; t=ans[t]);
		ans[t] = a; ans[a] = b;
	}

	int ac = 0;
	rrep(i, n) ac += (ans[i] == nxt[i]);
	cout << ac << '\n';
	rrep(i, n) cout << ans[i] << " \n"[i == n];
}

int main()
{
	cppio();
	int tc; cin >> tc;
rrep(tci, tc) {
	Work();
}
	return 0;
}