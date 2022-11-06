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

int n;
const int maxn = 2e5+10;

vector<int> e[maxn];
vector<int> re[maxn];

int tr[maxn];
int k;

int d[maxn];

int main()
{
	cppio();
	int m; cin >> n >> m;
	rrep(i, m) {
		int x, y; cin >> x >> y;
		e[y].pb(x);
		re[x].pb(y);
	}

	cin >> k;
	rrep(i, k) cin >> tr[i];

	int s = tr[1];
	int t = tr[k];

	fill(d+1, d+n+1, maxn);
	d[t] = 0;
	priority_queue<pp> pq;
	pq.emplace(0, t);
	while (pq.size()) {
		int D, x; tie(D, x) = pq.top(); pq.pop();
		D = -D+1;
		for(int y:e[x]) if (d[y] > D) {
			d[y] = D;
			pq.emplace(-D, y);
		}
	}

	int amin = 0, amax = 0;

	for(int i=1; i<k; ++i) {
		int fr = tr[i], to = tr[i+1];
		if (d[to] == d[fr] - 1) {
			int mc = 0;
			for(int y:re[fr]) if(d[y] == d[fr]-1) ++mc;
			if (mc >= 2) {
				++amax;
			}
		} else {
			++amin; ++amax;
		}
	}

	cout << amin << ' ' << amax << '\n';
	return 0;
}