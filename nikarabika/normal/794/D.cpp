//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e6,
	  middle = 5e5;
vector<int> adj[maxn],
	khoosh,
	st[maxn];
int num[maxn];
map<int, int> mat[maxn];
int n, m;
bool fnd[maxn];

bool isin(vector<int> &vec, int val){
	int id = lower_bound(all(vec), val) - vec.begin();
	if (id == sz(vec) or vec[id] != val) return false;
	return true;
}

void go(int pos, int d){
	if (sz(st[pos]) == 0)
		return;
	for (auto u : st[pos])
		for (auto v : adj[u])
			if (!fnd[v])
				st[pos + d].PB(v), fnd[v] = true;
	go(pos + d, d);
}

void get_khoosh(void){
	for (int i = 0; i < n; i++) {
		bool can = true;
		for (auto u : khoosh)
			if (!mat[i][u]){
				can = false;
				break;
			}
		if (can)
			khoosh.PB(i), fnd[i] = true;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
		mat[fi][se] = mat[se][fi] = true;
	}
	for (int i = 0; i < n; i++)
		sort(all(adj[i]));
	get_khoosh();
	if (count(fnd, fnd + n, true) == n){
		fill(num, num + n, 1);
		goto heaven;
	}
	for (auto u : khoosh) {
		for (auto v : adj[u])
			if (!fnd[v]) {
				for (auto w : adj[v])
					if (fnd[w])
						st[middle - 1].PB(w);
				goto hell;
			}
	}
hell:;
	for (auto u : khoosh) 
		if (!isin(st[middle - 1], u))
			st[middle].PB(u);
	go(middle - 1, -1);
	go(middle + 0, +1);
heaven:;
	if (count(fnd, fnd + n, true) != n)
		cout << "NO" << endl;
	else {
		LL sum = 0;
		for (int i = 1; i < maxn; i++) {
			sum += 1LL * sz(st[i]) * (sz(st[i]) - 1) / 2;
			sum += 1LL * sz(st[i]) * sz(st[i - 1]);
		}
		if (sum > maxn) {
			cout << "NO" << endl;
			return 0;
		}
		for (int i = 1; i + 1 < maxn; i++) {
			vector<int> vec;
			for (int j = i - 1; j <= i + 1; j++)
				for (auto u : st[j])
					vec.PB(u);
			sort(all(vec));
			for (auto u : st[i]){
				adj[u].PB(u);
				sort(all(adj[u]));
				if (adj[u] != vec) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
		for (int i = 0; i < maxn; i++)
			for (auto u : st[i])
				num[u] = i;
		cout << "YES" << endl;
		for (int i = 0; i < n; i++)
			cout << num[i] << ' ';
		cout << endl;
	}
	return 0;
}