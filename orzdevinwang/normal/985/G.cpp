#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
int n, m, vis[N];
vector<int> e[N], fe[N];
ull A, B, C;
ull sum(int l, int r) {
	return (ull) (r + l) * (r - l + 1) / 2;
}
ull calc0() {
	ull res = 0;
	L(i, 0, n - 1) res += (ull) sum(1, n - i - 2) * A * i;
	L(i, 0, n - 1) res += (ull) i * (n - i - 1) * B * i;
	L(i, 0, n - 1) res += (ull) sum(0, i - 1) * C * i;
	return res;
}
ull calc1() {
	ull res = 0;
	L(i, 0, n - 1) for(int j : e[i]) res += (A * i + B * j) * (n - j - 1) + C * sum(j + 1, n - 1);
	L(i, 0, n - 1) for(int j : e[i]) res += (B * i + C * j) * i + A * sum(0, i - 1);
	L(i, 0, n - 1) for(int j : e[i]) res += (A * i + C * j) * (j - i - 1) + B * sum(i + 1, j - 1);
	return res;
}
ull calc2() { 
	ull res = 0;
	L(i, 0, n - 1) 
		for(int j : e[i]) 
			for(int k : e[j]) res += A * i + B * j + C * k;
	L(i, 0, n - 1) 
		for(int j : e[i]) 
			for(int k : fe[j]) 
				if(i < k) 
					res += A * i + B * k + C * j;
	L(i, 0, n - 1) 
		for(int j : fe[i]) 
			for(int k : e[j]) 
				if(i < k) 
					res += A * j + B * i + C * k;
	return res;
}
ull calc3() {
	ull res = 0;
	L(i, 0, n - 1) {
		for(int j : e[i]) vis[j] = true;
		for(int j : e[i]) 
			for(int k : e[j]) if(vis[k]) res += A * i + B * j + C * k;
		for(int j : e[i]) vis[j] = false;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> A >> B >> C;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		if(u > v) swap(u, v);
		e[u].push_back(v), fe[v].push_back(u);
	}
	cout << calc0() - calc1() + calc2() - calc3() << "\n";
	return 0;
}