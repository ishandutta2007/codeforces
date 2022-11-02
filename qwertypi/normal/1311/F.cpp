#include <bits/stdc++.h>
#define int long long
using namespace std;

int x[200001], v[200001];

vector<pair<int, int>> vp;

#define MAXN 200001
struct Fenwick{
	int bit[MAXN];
	void add(int p, int x){
		while(p < MAXN){
			bit[p] += x;
			p += p & -p;
		}
	}
	int qry(int p){
		int res = 0;
		while(p > 0){
			res += bit[p];
			p -= p & -p;
		}
		return res;
	}
} bit1, bit2;

int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	vector<int> X;
	map<int, int> M;
	for(int i = 0; i < n; i++){
		X.push_back(x[i]);
	}
	sort(X.begin(), X.end());
	X.resize(unique(X.begin(), X.end()) - X.begin());
	for(int i = 0; i < X.size(); i++){
		M[X[i]] = i + 1;
	}
	
	for(int i = 0; i < n; i++){
		vp.push_back({v[i], x[i]});
	}
	sort(vp.begin(), vp.end());
	int ans = 0;
	for(int i = 0; i < n; i++){
		int id = M[vp[i].second];
		ans += bit1.qry(id) * vp[i].second - bit2.qry(id);
		// cout << bit1.qry(id) << ' ' << bit2.qry(id) << endl;
		bit1.add(id, 1);
		// cout << 1 << ' ' << id << ' ' << 1 << endl;
		bit2.add(id, vp[i].second);
		// cout << 2 << ' ' << id << ' ' << vp[i].second << endl;
	}
	cout << ans << endl;
}