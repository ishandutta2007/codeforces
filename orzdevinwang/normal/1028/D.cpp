#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 1e6 + 7, inf = 1e9 + 7, mod = 1e9 + 7;
int n, p, val[N], ns = 1;
char s[N]; 
set < int > no;
bool vis[N];
priority_queue < int > ql;
priority_queue < int, vi, greater < int > > qr;
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n ;
	ql.push(-inf);
	qr.push(inf);
	L(i, 1, n) {
		cin >> (s + 1);
		int p;
		cin >> p;
		if(s[2] == 'D') {
			if(p < ql.top()) ql.push(p);
			else if(p > qr.top()) qr.push(p); 
			else no.insert(p);
		} else {
			if(p < ql.top() || p > qr.top()) 
				return cout << 0 << '\n', 0;
			if(no.find(p) != no.end()) {
				ns = (ll) ns * 2 % mod;
				no.erase(no.find(p));
			} else {
				if(p == ql.top()) ql.pop();
				else {
					if(p != qr.top()) return cout << 0 << '\n', 0;
					qr.pop();
				} 
			}
			for(auto w : no)
				if(w < p) ql.push(w);
				else qr.push(w);
			no.clear();
		} 
	} 
	ns = (ll) ns * (sz(no) + 1) % mod; 
	cout << ns << '\n';
	return 0;
}