//sobskdrbhvk
//remember the flying...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2e5 + 16;
vector<LL> circ;
map<int, map<int, int> > cnt;
vector<int> vec[maxn];
short int ty[maxn];
LL x[maxn],
   y[maxn];

inline LL r2(int id) {
	return x[id] * x[id] + y[id] * y[id];
}

pii get_vec(int i, int j) {
	pii vec(x[i] + x[j], y[i] + y[j]);
	int d = __gcd(vec.L, vec.R);
	vec.L /= d;
	vec.R /= d;
	return vec;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q, n = 0;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> ty[i] >> x[i] >> y[i];
		if (ty[i] ^ 3)
			circ.PB(r2(i));
	}
	sort(all(circ));
	circ.resize(unique(all(circ)) - circ.begin());
	for (int i = 0; i < q; i++) {
		int id = lower_bound(all(circ), r2(i)) - circ.begin();
		if (ty[i] == 1) {
			n++;
			vec[id].PB(i);
			for (auto p : vec[id]) {
				pii vec = get_vec(i, p);
				cnt[vec.L][vec.R] += 1 + (i != p);
			}
		}
		else if (ty[i] == 2) {
			n--;
			for (auto p : vec[id]) {
				pii vec = get_vec(i, p);
				cnt[vec.L][vec.R] -= 1 + (x[i] != x[p] or y[i] != y[p]);
			}
			for (int j = 0; j < sz(vec[id]); j++)
				if (x[vec[id][j]] == x[i] and y[vec[id][j]] == y[i]) {
					vec[id].erase(vec[id].begin() + j);
					break;
				}
		}
		else {
			int d = __gcd(x[i], y[i]);
			x[i] /= d;
			y[i] /= d;
			cout << n - cnt[x[i]][y[i]] << '\n';
		}
	}
	return 0;
}