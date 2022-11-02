#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 13, Q = 1e5 + 13;
const int B = 400;


int back[N];
int go[N / B + 1][N];
int to[N / B + 1][N];

struct disjoint_set_union{
	vector<int> par, sz, max;
	void copy(const disjoint_set_union& d){
		this->par = d.par;
		this->sz = d.sz;
		this->max = d.max;
	}
	template<class InputIterator>
	void init(InputIterator first, InputIterator last){
		int n = std::distance(first, last);
		par.resize(n), sz.resize(n), max.resize(n);
		for(int i = 0; i < n; i++){
			par[i] = i;
			sz[i] = 1;
			max[i] = *(first + i);
		}
	}
	int root(int x){
		if(par[x] == x) return x;
		return par[x] = root(par[x]);
	}
	int64_t get_max(int x){
		return max[root(x)];
	}
	bool join(int x, int y){
		x = root(x), y = root(y);
		if(x == y) return false;
		par[y] = x;
		sz[x] += sz[y];
		max[x] = std::max(max[x], max[y]);
		return true;
	}
};

int main(){
	int n, m, q;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		back[i] = i;
	}
	for(int j = 0; j <= n / B; j++){
		for(int i = 0; i < n; i++){
			to[j][i] = i;
		}
	}
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		l--; r--;
		back[r] = l;
		for(int j = r / B + 1; j <= n / B; j++){
			to[j][l] = max(to[j][l], r);
		}
	}
	for(int j = 0; j <= n / B; j++){
		disjoint_set_union dsu;
		dsu.init(to[j], to[j] + n);
		for(int i = n - 1; i >= 0; i--){
			for(int k = i; dsu.root(k) + 1 <= to[j][i]; k = dsu.root(k)){
				dsu.join(dsu.root(k) + 1, dsu.root(k));
			}
			go[j][i] = dsu.get_max(i);
		}
	}
	cin >> q;
	for(int i = 0; i < q; i++){
		int x, y;
		cin >> x >> y;
		x--; y--; 
		int ans;
		if(y - x < B){
			ans = x;
			for(int j = x + 1; j <= y; j++){
				if(x <= back[j] && back[j] <= ans){
					ans = j;
				}
			}
		}else{
			ans = go[y / B][x];
			for(int j = y / B * B; j <= y; j++){
				if(x <= back[j] && back[j] <= ans){
					ans = j;
				}
			}
		}
		cout << ans + 1 << endl;
	}
}