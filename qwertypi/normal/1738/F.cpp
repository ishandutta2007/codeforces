#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int d[1001], c[1001];
int n;

int qry(int v){
	cout << "? " << v << endl;
	int r; cin >> r;
	return r;
}

void ans(){
	cout << "! ";
	for(int i = 1; i <= n; i++){
		cout << c[i] << ' ';
	}
	cout << endl;
}

int cc = 1;

struct DSU{
	int dsu[1001];
	void init(int n){
		for(int i = 1; i <= n; i++){
			dsu[i] = i;
		}
	}
	int f(int x){
		return x == dsu[x] ? x : dsu[x] = f(dsu[x]);
	}
	void g(int x, int y){
		x = f(x), y = f(y);
		if(x == y) return;
		dsu[x] = y;
	}
} dsu;

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> d[i];
	}
	fill(c, c + n + 1, 0);
	dsu.init(n);
	vector<pair<int, int>> vp;
	for(int i = 1; i <= n; i++){
		vp.push_back({d[i], i});
	}
	sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b){
		return a.fi > b.fi;
	});
	for(int i = 0; i < n; i++){
		if(c[vp[i].se] == 0){
			c[vp[i].se] = true;
			for(int j = 0; j < d[vp[i].se]; j++){
				int r = qry(vp[i].se);
				dsu.g(r, vp[i].se);
				if(c[r]) break;
				c[r] = true;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		c[i] = dsu.f(i);
	}
	ans();
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}