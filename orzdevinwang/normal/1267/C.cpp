#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;

const int N = 1e5 + 7;

int n, m, d[N], cnt;
int sum1 = 0, sum2 = 0;

int h[N];

int f[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y) {
	x = find(x), y = find(y);
	if(x != y) f[x] = y;  
	else assert(false);
}

vi vc[N], qwq;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> d[i], cnt += d[i];
	if(cnt & 1) return cout << -1 << '\n', 0;
	cnt >>= 1;
	m = cnt, cnt = m - n + 1; 
	if(m < n - 1 || m > n - 1 + (n - 1) / 2) return cout << -1 << '\n', 0;
	L(i, 1, n) if(d[i] >= 2) sum1 += 1, sum2 += d[i] / 2;
	
	if(n == 2 && m == 1) 
		return cout << m << '\n' << 2 << ' ' << 1 << ' ' << 2 << '\n', 0;
	
	if(sum1 < cnt * 2 + 1 || sum2 < cnt * 3) 
		return cout << -1 << '\n', 0;
	
	cout << m << '\n';
	
	L(i, 1, n) 
		h[i] = d[i] / 2;
	
	auto out = [&] (int u, int v) {
		cout << 2 << ' ' << u << ' ' << v << '\n';
//		cout << u << ' ' << v << '\n';
	} ;
	
	L(i, 1, n) 
		f[i] = i;
	
	L(zz, 1, cnt) {
		int mx = 0;
		L(j, 1, n) if(d[j] > d[mx]) mx = j;
		
		if(d[mx] == 2) {
			L(i, 1, n) assert(d[i] == 0 || d[i] == 2) ;
			vi pm;
			L(i, 1, n) if(d[i] == 2) pm.emplace_back(i);
			L(i, 0, sz(pm) - 1) 
				cout << 2 << ' ' << pm[i] << ' ' << pm[(i + 1) % sz(pm)] << '\n';
			return 0;
		}
		h[mx] -= 1, d[mx] -= 2;
		
		int w1 = 0, w2 = 0;
		L(j, 1, n) if(find(j) != find(mx) && h[j] > 0 && (!w1 || d[w1] > d[j])) w1 = j;
		h[w1] -= 1, d[w1] -= 2;	
		L(j, 1, n) if(find(j) != find(mx) && 
			find(j) != find(w1) && h[j] > 0 && (!w2 || d[w2] > d[j])) w2 = j;
		h[w2] -= 1, d[w2] -= 2;
		out(mx, w1);
		out(w2, w1);
		out(mx, w2);
		
		merge(mx, w1);
		merge(mx, w2);
	} 
	
	L(i, 1, n) L(j, 1, d[i]) vc[find(i)].emplace_back(i);
			
	L(i, 1, n) if(f[i] == i) qwq.emplace_back(i);
	
	L(i, 1, sz(qwq) - 1) {
		
		int r = 0;
		for(const int &u : qwq) 
			if(sz(vc[u]) == 1) r = u;
		
		int ru = vc[r].back();
		vc[r].pop_back();
		
		int mx = 0;
		for(const int &u : qwq) 
			if(sz(vc[u]) > sz(vc[mx])) mx = u;
		
		int rv = vc[mx].back();
		vc[mx].pop_back();
		
		out(ru, rv);	
	}
	return 0;
}