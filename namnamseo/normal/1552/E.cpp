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

const int maxn = int(2e2) + 10;

int n, k;
int po[maxn][maxn];
int a[maxn*maxn];
int wh[maxn*maxn];

pp ans[maxn];
int cf;
bitset<maxn> done;

const int M = 16384;
int t[M<<1];

bool ok(int l, int r) {
	int mx = 0;
	for (l+=M, r+=M; l<=r; l/=2, r/=2) {
		if (l%2==1) mx = max(mx, t[l++]);
		if (r%2==0) mx = max(mx, t[r--]);
	}
	return mx < ((n+k-2)/(k-1));
}

void Upd(int l, int r) {
	for (int i=l; i<=r; ++i) {
		++t[M+i];
		for (int p=(M+i)/2; p; p/=2) {
			t[p] = max(t[p*2], t[p*2+1]);
		}
	}
}

int main()
{
	cppio();
	cin >> n >> k;
	rrep(i, n*k) {
		int x; cin >> x;
		static int pon[maxn];
		a[i] = x;
		wh[i] = ++pon[x];
		po[x][pon[x]] = i;
	}

	rrep(i, n*k) {
		if (cf == n) break;
		int c = a[i];
		if (done[c]) continue;

		int w = wh[i];
		if (w == 1) continue;
		int j = po[c][w-1];

		if (ok(j, i)) {
			done[c] = true;
			ans[c] = {j, i};
			Upd(j, i);
			++cf;
		}
	}

	assert(cf == n);
	rrep(i, n) {
		auto [x, y] = ans[i];
		cout << x << ' ' << y << '\n';
	}

	return 0;
}