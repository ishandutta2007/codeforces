#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
void Min(int &x, int y) { if(x > y) x = y; }
void Max(int &x, int y) { if(x < y) x = y; }
const int N = 1e6 + 7; 
const int mod = 1e9 + 9;
int n, x[N], y[N], deg[N], dow[N], now;
set< int > st;
map< pii , int> mp;
void sc(int x, int y) {
	int P = mp[mkp(x, y)];
	if(P) {
		deg[P] --;
		if(deg[P] == 0) st.insert(P);
	}
}
void chk(int X, int Y) {
	int i = mp[mkp(X, Y)];
	if(!i) return;
	int A, B, C;
	A = mp[mkp(X, Y - 1)];
	B = mp[mkp(X - 1, Y - 1)];
	C = mp[mkp(X + 1, Y - 1)];
	dow[i] = (!!A) + (!!B) + (!!C);
	if(dow[i] != 1) return;
	if(A) {
		if(!deg[A]) st.erase(A);
		deg[A] ++;	
	}
	if(B) {
		if(!deg[B]) st.erase(B);
		deg[B] ++;		
	}
	if(C) {
		if(!deg[C]) st.erase(C);
		deg[C] ++;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> x[i] >> y[i], mp[mkp(x[i], y[i])] = i;
	L(i, 1, n) st.insert(i);
	L(i, 1, n) {
		int A, B, C;
		A = mp[mkp(x[i], y[i] - 1)];
		if(A) dow[i] ++;
		B = mp[mkp(x[i] - 1, y[i] - 1)];
		if(B) dow[i] ++;
		C = mp[mkp(x[i] + 1, y[i] - 1)];
		if(C) dow[i] ++;
		chk(x[i], y[i]);
	}
	int flag = 0;
	L(r, 1, n) {
		now = (ll) now * n % mod;
		flag ^= 1; int v;
		if(flag) v = *st.rbegin();
		else v = *st.begin();
		st.erase(v);
		mp.erase(mkp(x[v], y[v]));
		(now += v - 1) %= mod;
		if(dow[v] == 1) {
			sc(x[v] + 1, y[v] - 1);
			sc(x[v], y[v] - 1);
			sc(x[v] - 1, y[v] - 1);
		}
		chk(x[v] + 1, y[v] + 1);
		chk(x[v], y[v] + 1);
		chk(x[v] - 1, y[v] + 1);
	}
	cout << now << endl;
	return 0;
}