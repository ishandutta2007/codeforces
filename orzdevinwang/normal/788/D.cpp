#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 2e5 + 7, inf = 1e8;
int r[N], A[N], B[N], n, m;
set < int > st;
int query (int x, int y) {
	cout << 0 << ' ' << x << ' ' << y << endl;
	int u;
	cin >> u;
	return u;
}
void divide (int l, int r) {
	if(r <= l + 1) return ;
	if((r - l) % 2 == 0) {
		int mid = (r + l) / 2;
		int c = query (mid, mid);
		if(c == (r - l) / 2) return ;
		if(query (mid - c, mid - c) == 0) 
			st.insert(mid - c), divide(l, mid - c), divide(mid - c, r);
		else 
			st.insert(mid + c), divide(l, mid + c), divide(mid + c, r);
		return ;
	}
	int mid = (l + r + inf * 2) / 2 - inf, d = (r - l) / 2;
	int c = query(mid, mid);
	if(c == d) {
		if(query(mid + d, mid + d) == 0) st.insert(mid + d), divide(l, mid + d);
		return ;
	}
	if(query (mid - c, mid - c) == 0) 
		st.insert(mid - c), divide(l, mid - c), divide(mid - c, r);
	else 
		st.insert(mid + c), divide(l, mid + c), divide(mid + c, r);
}
int main() {
	int cr = inf - query(inf, inf), cl = -inf + query(-inf, -inf);
	st.insert(cl), st.insert(cr), divide(cl, cr);
	int ano = -1;
	L(i, 0, 114514) if(st.find(i) == st.end()) {
		ano = i;
		break;
	}
	for(const int &x : st) {
		if(query (x, ano) == 0) A[++n] = x;
		if(query (ano, x) == 0) B[++m] = x; 
	}
	cout << 1 << " " << n << ' ' << m << endl;
	L(i, 1, n) cout << A[i] << " ";
	cout << endl;
	L(i, 1, m) cout << B[i] << " ";
	cout << endl;
	return 0;
}