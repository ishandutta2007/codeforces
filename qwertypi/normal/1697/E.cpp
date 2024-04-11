#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pi pair<int, int>
using namespace std;

const int mod = 998244353;
struct Point{
	int x, y;
	bool operator< (const Point& o) const{
		return x < o.x || x == o.x && y < o.y;
	}
};

int d(Point a, Point b){
	return abs(a.x - b.x) + abs(a.y - b.y);
}

vector<Point> vp;

int _min[100];

struct DSU{
	int dsu[100];
	bool ok[100];
	void in(int n){
		for(int i = 0; i < n; i++){
			dsu[i] = i;
			ok[i] = true;
		}
	}
	int f(int x){
		if(x == dsu[x]) return x;
		return dsu[x] = f(dsu[x]);
	}
	void join(int x, int y){
		x = f(x), y = f(y);
		dsu[x] = y;
	}
} dsu;

int fact[101];

int pm(int a, int b){
	if(b == 0) return 1;
	return pm(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod;
}

int mi(int a){
	return pm(a, mod - 2);
}

int P(int n, int r){
	return fact[n] * mi(fact[n - r]) % mod;
}

int dp1[10001], dp2[10001];
int32_t main(){
	int n;
	cin >> n;
	fact[0] = 1;
	for(int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		vp.push_back({x, y});
	}
	sort(vp.begin(), vp.end());
	vector<pair<int, pi>> dis;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			dis.push_back({d(vp[i], vp[j]), {i, j}});
		}
	}
	sort(dis.begin(), dis.end());
	for(int i = 0; i < n; i++) _min[i] = (1 << 30);
	for(auto i : dis){
		_min[i.se.fi] = min(_min[i.se.fi], i.fi);
		_min[i.se.se] = min(_min[i.se.se], i.fi);
	}
	dsu.in(n);
	for(auto i : dis){
		if(_min[i.se.fi] == i.fi && _min[i.se.se] == i.fi){
			dsu.join(i.se.fi, i.se.se);
		}
	}
	vector<int> dead;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(dsu.f(i) == dsu.f(j) && (d(vp[i], vp[j]) > _min[i] || d(vp[i], vp[j]) > _min[j])){
				dsu.ok[dsu.f(i)] = 0;
				dead.push_back(dsu.f(i));
			}
			if(dsu.f(i) != dsu.f(j) && d(vp[i], vp[j]) == _min[i]){
				dead.push_back(dsu.f(i));
			}
		}
	}
	sort(dead.begin(), dead.end());
	vector<int> to_fix; 
	for(int i = 0; i < n; i++){
		if(binary_search(dead.begin(), dead.end(), dsu.f(i))){
			to_fix.push_back(i);
		}
	}
	for(auto i : to_fix){
		dsu.dsu[i] = i;
	}
	vector<int> v;
	map<int, int> M;
	for(int i = 0; i < n; i++){
		M[dsu.f(i)]++;
	}
	for(auto i : M){
		v.push_back(i.second);
	}
	dp1[0] = 1;
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j <= n; j++){
			if(v[i] != 1) dp2[j + v[i]] += dp1[j];
			dp2[j + 1] += dp1[j];
		}
		for(int j = 0; j <= n; j++){
			dp2[j] %= mod;
			swap(dp1[j], dp2[j]);
			dp2[j] = 0;
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		ans += P(n, i) * dp1[i] % mod;
	}
	ans %= mod;
	cout << ans << endl;
}