#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define sz(a) ((int) (a).size())
#define mkp make_pair
#define vi vector<int>
using namespace std;
const int N = 5e5 + 7;
int n, a, b, c;
int up1[10], up2[10], pw[10];
int qwq(int x) {
	L(i, 2, sqrt(x)) if(x % i == 0) return true;
	return false;
}
int rmain() {
	cin >> a >> b >> c;
	cout << up1[a - c] * pw[c - 1] << " " << up2[b - c] * pw[c - 1] << "\n";
	return 0;
}
void init() {
	int t = 1;
	L(i, 0, 9) {
		if(i) t *= 10;
		pw[i] = t;
		int now = t;
		while(qwq(now)) ++now;
		up1[i] = now, ++now;
		while(qwq(now)) ++now;
		up2[i] = now;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init();
	int T;
	cin >> T;
	while(T--) rmain();	
	return 0;
} 
// To Cheat, To attack!