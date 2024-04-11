// i can't understand it, but i'm shocked a lot. 
#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 107;
const ll linf = 1e14;
ll f[N][N]; //  goodeat  
ll nowa;
char s[N];
bool check(ll w) {
	if(w > linf) return false; 
	cout << "? " << w << endl;
	string op;
	cin >> op;
	if(op[0] == 'L') nowa += w;
	else nowa -= w; 
	return op[0] == 'L';
}
void DO(int a, int b, ll l, ll r) {
	if(l == r) return cout << "! " << l << '\n', void ();
	if(b == 0) return check(l), DO(a - 1, b + 1, l, r), void ();
	ll ck = min(r, l + f[a - 1][b - 1]);
	while (nowa < ck) check(l);
	if(check(ck)) DO(a - 1, b + 1, ck, r);
	else DO(a - 1, b - 1, l, ck - 1);
}
void Main () {
	nowa = 1;
	ll S = 1;
	while (check(S)) S <<= 1;
	ll l = S >> 1, r = min(linf, S - 1);
	L(i, 0, 60) if(f[i][0] >= r - l + 1) return DO(i, 1, l, r);
	assert (0);
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	L(i, 0, 60) f[0][i] = 1;
	L(i, 1, 60) L(j, 0, 60) f[i][j] = f[i - 1][j + 1] + (j == 0 ? 0 : f[i - 1][j - 1]);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0; 
}