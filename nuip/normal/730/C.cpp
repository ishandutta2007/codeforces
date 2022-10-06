#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

const ll MOD = 1e9+7;

int n, m, Q, g[8192], v[16384], nxt[16384], idx, q[8192], d[8192][8192];

struct P{ int c, k, p; };
P a[8192];

bool comp(const P &a, const P &b) {
	return a.p < b.p;
}

void bfs(int S) {
	reps(i, 1, n+1) d[S][i] = -1;
	int h, t;
	h = t = 1;
	q[1] = S;
	d[S][S] = 0;
	while(h <= t) {
		int x = q[h];
		for(int i = g[q[h++]]; i; i = nxt[i]) {
			if(d[S][v[i]] < 0) {
				q[++t] = v[i];
				d[S][q[t]] = d[S][x] + 1;
			}
		}
	}
}

bool check(int S, int R, int M, int dist) {
	reps(i, 1, m+1) {
		if(d[S][a[i].c] <= dist && d[S][a[i].c] >= 0) {
			int tmp = min(R, a[i].k);
			if((ll)tmp * a[i].p > M) return false;
			R -= tmp;
			M -= tmp * a[i].p;
			if(!R) return true;
		}
	}
	return false;
}

int solve() {
	int S, R, M;
	cin >> S >> R >> M;
	int l = 0, r = n - 1, mid, res = -1;
	while(l <= r) {
		mid = (l + r) / 2;
		if(check(S, R, M, mid)) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return res;
}

int main(){
	cin >> n >> m;
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		v[++idx] = y;
		nxt[idx] = g[x];
		g[x] = idx;
		
		v[++idx] = x;
		nxt[idx] = g[y];
		g[y] = idx;
	}
	reps(i, 1, n+1) bfs(i);
	//reps(i, 1, n+1) reps(j, 1, n+1) cout << "d[" << i << "][" << j << "] = " << d[i][j] << endl;

	cin >> m;
	reps(i, 1, m+1) cin >> a[i].c >> a[i].k >> a[i].p;
	sort(a+1, a+1+m, comp);
	cin >> Q;
	while(Q--) cout << solve() << endl;
	return 0;
}