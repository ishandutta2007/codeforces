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
const int inf = int(1e9);
int n, m;

vector<int> _ea[2][maxn];
vector<int> *e = _ea[0], *re = _ea[1];

int dist[maxn];

queue<int> q, nq;

const ll mod = 998'244'353;
ll pow2(int x) {
	if (x < 0) return 0;
	ll ret = 1, b = 2;
	while (x) {
		if (x&1) (ret *= b) %= mod;
		(b *= b) %= mod; x >>= 1;
	}
	return ret;
}

int main()
{
	cppio();
	cin >> n >> m;

	rep(i, m) {
		int a, b; cin >> a >> b;
		e[a].pb(b); re[b].pb(a);
	}

	fill(dist+2, dist+n+1, inf);
	q.push(1);
	nq.push(1);

	auto iter = [&] {
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int y:e[x]) {
				if (dist[y] > dist[x]+1) {
					dist[y] = dist[x]+1;
					q.push(y);
					nq.push(y);
				}
			}
		}
		swap(e, re);
		swap(q, nq);
	};

	int step;
	for (step=0;;++step) {
		iter();
		if (dist[n] != inf) break;
	}

	vector<int> ans;

	rep(j, 20) {
		ans.pb(dist[n]);
		iter();
	}

	int bi = 0;
	rrep(j, 19) {
		ll df = ans[bi] - ans[j];
		if (step+bi <= 20) {
			ll du = df >> (step+bi);
			ll dd = (df - (du << (step+bi)));
			if (du + !!dd > (1ll<<(j-bi)) - 1) {
				bi = j;
			}
		}
	}

	cout << (ans[bi] + pow2(step+bi) + mod - 1) % mod << '\n';

	return 0;
}