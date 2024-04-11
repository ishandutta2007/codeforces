#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;
 
#define FNAME ""

const int MAX_N = 16;

vi v[MAX_N];
ll sum[MAX_N];
vector<pii> ans;
map<ll, int> was;  
int d[1 << MAX_N], used[MAX_N];
vector<pii> c[1 << MAX_N];
  
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int k;
	cin >> k;
	ll allSum = 0;
	forn (i, k) {
		int n;
		cin >> n;
		v[i].resize(n);
		forn (j, n)
			cin >> v[i][j], was[v[i][j]] = i, sum[i] += v[i][j];
		allSum += sum[i];
		sort(all(v[i]));
	}
	if (allSum % k != 0) {
		cout << "No";
		return 0;
	}
	ll buck = allSum / k;
	d[0] = 1;
	ans.resize(k);
	fill(all(ans), mp(0, -1));
	c[0] = ans;
	forn (i, k) {
		forn (j, sz(v[i])) {
			ll cur = v[i][j];
			ll orCur = cur;
			ll ind = i;
			bool run = 1;
			bool ok = 1;
			fill(all(ans), mp(0, -1));
			fill(used, used + MAX_N, 0);
			int mask = 0;
			while (ind != i || run) {
				run = 0;
				mask |= (1 << ind);
				ll nxt = buck - (sum[ind] - cur);
				if (was.count(nxt)) {
					int nxtInd = was[nxt];
					if (used[nxtInd]) {
						ok = 0;
						break;
					}
					//cout << cur << " " << nxtInd << " " << nxt << " " << ind << "\n";
					ans[nxtInd] = mp(nxt, ind);
					used[nxtInd] = 1;
					ind = nxtInd;
					cur = nxt;
				} else {
					ok = 0;
					break;
				}
			}
			if (ok && cur == orCur) {
				d[mask] = 1;
				c[mask] = ans;
			}
		}
	}
	forn (mask, (1 << k)) {
		if (d[mask])
			continue;
		for (int s = mask; s; s = (s - 1) & mask) {
			if (s == mask || s == 0)
				continue;
			if (d[s] && d[s ^ mask]) {
				c[mask].resize(k);
				d[mask] = 1;
				forn (j, k) {
					if (c[s][j].snd != -1)
						c[mask][j] = c[s][j];
					if (c[mask ^ s][j].snd != -1)
						c[mask][j] = c[mask ^ s][j];
				}
				break;
			}
		}
	}
	if (!d[(1 << k) - 1]) {
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	forn (i, k)
		cout << c[(1 << k) - 1][i].fst << " " << c[(1 << k) - 1][i].snd + 1 << "\n";
	return 0;
}