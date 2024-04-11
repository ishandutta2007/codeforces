#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
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
pp p[maxn];

struct tree {
	const static int M = maxn;
	int t[M];
	bool on[M];
	int N;
	int C;

	void init(int n) {
		fill(t+1, t+n+1, 0);
		fill(on+1, on+n+1, 0);
		N = n;
		C = 0;
	}

	void upd(int p) {
		if(on[p]) return;
		on[p] = 1;
		++C;
		while(p <= N) {
			t[p]++;
			p += (p & (-p));
		}
	}

	int rsum(int p) {
		if(p < 0) return 0;
		p = min(p, N);

		int ret = 0;
		while(p) {
			ret += t[p]; p &= (p-1);
		}
		return ret;
	}

	int rsum(int l, int r) {
		if(l > r) return 0;
		return rsum(r) - rsum(l-1);
	}
} tL, tR;

pp tmp[maxn];

ll ans;

#define yn yn_

int xv[maxn], xn;
int yv[maxn], yn;

void work(int l, int r) {
	if(l > r) return;

	if(p[l].x == p[r].x) {
		ans += r-l+1;
		reverse(p+l, p+r+1);
		return;
	}

	int xL = p[l].x, xR = p[r].x;

	int tn = 0;
	for(int i=l; i<=r; ++i) {
		if(tn == 0 || tmp[tn-1].x != p[i].x) {
			tmp[tn++] = {p[i].x, i};
		}
	}

	int gj, mid;
	tie(gj, mid) = tmp[tn/2];
	//printf("(%d, %d) -> (%d, %d) / (%d, %d)\n", l, r, l, mid-1, mid, r);
	work(l, mid-1); work(mid, r);

	int lp = l, rp = mid;
	tn = 0;
	while(lp < mid || rp <= r) {
		if(lp < mid && (rp > r || p[lp].y >= p[rp].y)) {
			tmp[tn++] = p[lp++];
		} else {
			tmp[tn++] = p[rp++];
		}
	}

	copy(tmp, tmp+tn, p+l);

	tL.init(gj-xL);
	tR.init(xR-(gj-1));

	for(int i=l; i<=r; ) {
		int j;
		for(j=i; j<=r && p[i].y == p[j].y; ++j);

		//printf("take care of y %d\n", yv[p[i].y-1]);

		int lB = xL-1, rB = xR+1;

		for(int k=i; k<j; ++k) {
			if(p[k].x < gj) {
				lB = max(lB, p[k].x);
				tL.upd(p[k].x - (xL-1));
			} else {
				rB = min(rB, p[k].x);
				tR.upd(p[k].x - (gj-1));
			}
		}

		/*printf("lB %d rB %d lc %d rc %d lsum %d rsum %d\n",
		xv[lB-1], xv[rB-1],
		tL.C, tR.C,
			tL.rsum(lB+1 - (xL-1), gj-xL),
			tR.rsum(1, rB-gj));*/

		ans += tL.C * 1ll * tR.C -
			tL.rsum(lB+1 - (xL-1), gj-xL) * 1ll *
			tR.rsum(1, rB-gj);

		i = j;
	}
}

int main()
{
	cppio();
	cin >> n;
	rrep(i, n) cin >> p[i].x >> p[i].y;

	sort(p+1, p+n+1);

	rrep(i, n) {
		xv[i-1] = p[i].x;
		yv[i-1] = p[i].y;
	}
	/*sort(xv, xv+n);*/ xn = unique(xv, xv+n) - xv;
	sort(yv, yv+n); yn = unique(yv, yv+n) - yv;

	rrep(i, n) {
		p[i].x = lower_bound(xv, xv+xn, p[i].x) - xv + 1;
		p[i].y = lower_bound(yv, yv+yn, p[i].y) - yv + 1;
	}

	work(1, n);

	cout << ans << endl;
	return 0;
}