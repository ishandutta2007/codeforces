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

const int maxn = 2e5 + 10;

int n, m, k;

pp da[maxn];
pp db[maxn];

struct mob {
	int x, y, z;
} dm[maxn];

const int M = 1048576 * 2;
int tree[M];
int lazy[M];
int B;
const int inf = int(2e9) + 10;

void acq(int p, int v) {
	tree[p] += v;
	lazy[p] += v;
}

void flush(int p) {
	if (!lazy[p]) return;
	acq(p*2, lazy[p]);
	acq(p*2+1, lazy[p]);
	lazy[p] = 0;
}

void upd(int l, int r, int x, int p=1, int ml=1, int mr=B) {
	if (r < ml || mr < l) return;
	if (l <= ml && mr <= r) {
		acq(p, x);
		return;
	}
	flush(p);
	int mid = (ml+mr)/2;
	upd(l, r, x, p*2, ml, mid);
	upd(l, r, x, p*2+1, mid+1, mr);
	tree[p] = max(tree[p*2], tree[p*2+1]);
}

int main()
{
	cppio();
	cin >> n >> m >> k;

	rrep(i, n) cin >> da[i].x >> da[i].y;
	rrep(i, m) cin >> db[i].y >> db[i].x;

	rrep(i, k) {
		cin >> dm[i].x >> dm[i].y >> dm[i].z;
		++dm[i].x;
		++dm[i].y;
	}

	sort(da+1, da+n+1);
	sort(db+1, db+m+1);
	sort(dm+1, dm+k+1, [&](const mob& a, const mob& b) {
		return a.x < b.x;
	});

	rrep(i, m) B = max(B, db[i].y);

	int lasty = 0;

	for (int i=1, j; i<=m; i=j) {
		for(j=i+1; j<=m && db[i].x == db[j].x; ++j);

		if (lasty < db[j-1].y) {
			upd(lasty+1, db[j-1].y, -db[j-1].x);
			lasty = db[j-1].y;
		}
	}

	int ans = -inf;
	int pt = 1;
	rrep(i, n) {
		while (pt<=k && dm[pt].x <= da[i].x) {
			if (dm[pt].y <= B) {
				upd(dm[pt].y, B, dm[pt].z);
			}
			++pt;
		}

		ans = max(ans, tree[1]-da[i].y);
	}

	cout << ans << endl;
	return 0;
}