#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define sz(a) ((int) (a).size()) 
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e6 + 7, M = 5e6 + 7;
int n, m, mx[M], v[M], a[N];
bool mp[M];
void Main() {
	cin >> n >> m;
	int mn = m + 1;
	L(i, 1, n) cin >> a[i], mn = min(mn, a[i]), mp[a[i]] = true;
	L(i, 1, m) mx[i] = m * 2 + 1, v[i] = 1;
	R(i, m, 2) {
		mx[1] = i;
		L(j, 1, m / i) 
			if(mx[i * j] > mx[j]) {
				if(mp[i * j]) v[i + 1] = max(v[i + 1], mx[i * j]);
				mx[i * j] = mx[j];
			}
	}  
	mx[1] = 1;
	L(i, 1, n) v[1] = max(v[1], mx[a[i]]);
	int ns = m + 1;
	L(i, 1, mn) v[i] = max(v[i], v[i - 1]), ns = min(ns, v[i] - i);
	cout << ns << '\n';
	L(i, 1, n) mp[a[i]] = false;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int t;
	cin >> t;
	while(t--) Main(); 
	return 0;
}