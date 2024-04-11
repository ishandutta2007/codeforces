#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7;
int n, p[N];
ll ns;
int mp[N];
inline int dis(int x, int y) {
	return x <= y ? y - x : y - x + n;
}

inline bool inside(int u, int v, int p) {
	return dis(u, v) == dis(u, p) + dis(p, v);
}

int c_a[N], num;
void add (int x, int w) {
	num += w;
	for (; x <= n; x += x & -x) c_a[x] += w;
}
int query (int x) {
	int ret = 0;
	for (; x; x -= x & -x) ret += c_a[x];
	return ret;
}

inline int sum(int l, int r) {
	return (l > r) * num + query(r) - query(l);
}

void Main() {
	cin >> n, ns = 0;
	L(i, 1, n) {
		cin >> p[i];
		add(i, 1);
		mp[p[i]] = i;
	} 
	add(mp[1], -1), add(mp[2], -1);
	int gc = mp[1], p = 2;
	L(i, 3, n) {
		if(!inside(gc % n + 1, mp[i], mp[i - 1])) {
//			cout << "gc = " << gc << '\n';
			while(p < i && inside(gc % n + 1, mp[i], mp[p])) 
				ns += (ll) (p - 1) * sum(gc, mp[p]), gc = mp[p], ++p;
			ns += (ll) (p - 1) * sum(gc, mp[i]);
//			cout << " p = " << p << endl;
			gc = mp[i];
		}
		add(mp[i], -1);
	}
	cout << ns << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main(); 
	return 0;
}