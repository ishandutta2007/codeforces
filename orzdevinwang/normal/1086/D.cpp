#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n, m;
char s[N];
set < int > w[3];
int getv (char x) {
	if(x == 'P') return 0;
	if(x == 'R') return 1;
	if(x == 'S') return 2; 
	return assert(0), -1;
}

struct fenwt {
	int a[N], n = N - 1;
	void init () {
		L(i, 1, n) if(i + (i & -i) <= n) a[i + (i & -i)] += a[i];
	}
	void add (int x, int  w) {
		for (; x <= n; x += x & -x) a[x] += w;
	}
	int query (int x) {
		int ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	int get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
} st[3];

int getw (int x) {
	int xwin = (x + 1) % 3, xlose = (x + 2) % 3;
	if(!sz(w[x])) return 0;
	if(!sz(w[xlose])) return sz(w[x]);
	if(!sz(w[xwin])) return 0;
	return sz(w[x]) - st[x].get (* w[xlose].begin(), * w[xwin].begin()) - 
	st[x].get (* w[xwin].rbegin(), * w[xlose].rbegin());
}

char qwq[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> (s + 1);
	L(i, 1, n) w[getv(s[i])].insert(i), st[getv(s[i])].add(i, 1);
//	cout << " is " << getw(2) << '\n';
	cout << getw (0) + getw(1) + getw(2) << '\n';
	while (m--) {
		int p;
		cin >> p >> (qwq + 1);
		st[getv(s[p])].add(p, -1);
		w[getv(s[p])].erase(p);
		
		s[p] = qwq[1];
		st[getv(s[p])].add(p, 1);
		w[getv(s[p])].insert(p);
		
		cout << getw(0) + getw(1) + getw(2) << '\n';
	}
	return 0;
}