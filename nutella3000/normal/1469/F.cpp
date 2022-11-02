#include <bits/stdc++.h>
       
using namespace std;
       
       
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
       
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
        
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
       
const int inf = 2e9 + 7;
	
auto comp = [](const pii& x,const pii& y){return mp(-x.fi + 1 - x.se, x.fi) < mp(-y.fi + 1 - y.se, y.fi);};

int x = inf;
multiset<pii> s;
multiset<pii, decltype(comp)> big(comp);
int big_sum = 0, small_sum = 0, small_sz = 0; 


int it = 0;

void del(pii v) {
	if (big.find(v) != big.end()) big.erase(big.find(v)), big_sum -= v.se;
	else small_sz--, small_sum -= (-v.fi + 1);
	s.erase(s.find(v));
}

void add(pii v) {
	if (x - v.fi + 1 > v.se) big.emplace(v), big_sum += v.se;
	else small_sz++, small_sum += (-v.fi + 1);
	s.emplace(v);
}

int f(int x) {
	return big_sum + x * small_sz + small_sum;
}



void solve() {
	add({0, 1});

	int n, k;
	cin >> n >> k;
	vector<int> l(n);
	for(int i = 0;i < n;i++) {
		cin >> l[i];
	}

	sort(all(l));
	reverse(all(l));

	for(int v_l : l) {
		pii v = *s.begin();
		del(v);
		pii v1 = {v.fi + 1, v.se - 1}, v2 = {v.fi + 2, v_l / 2}, v3 = {v.fi + 2, (v_l - 1) / 2};
		if (v1.se != 0) add(v1);
		add(v2), add(v3);

		if (f(x) < k) continue;
		while(sz(big)) {

			pii v = *big.begin();
			int new_x = -(- v.fi + 1 - v.se);
			if (f(new_x) >= k) {
				del(v);
				x = new_x;
				add(v);
			}else {
				int l = new_x, r = x;
				while(r - l > 1) {
					int mid = (l + r) / 2;
					if (f(mid) >= k) r = mid;
					else l = mid;
				}
				x = r;
				break;
			}
		}

		if (big.empty()) {
			int l = -1, r = x;
			while(r - l > 1) {
				int mid = (l + r) / 2;
				if (f(mid) >= k) r = mid;
				else l = mid;
			}
			x = r;
		}
	}

	cout << (x == inf ? -1 : x) << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}