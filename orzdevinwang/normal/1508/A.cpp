#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) ((int) a.size())
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7;
int n, m, a[N], cnt[4], tot[2], p[2], t[2][N];
char s[3][N]; 
int rmain() {
	cnt[0] = cnt[1] = cnt[2] = 0;
	cin >> n >> (s[0] + 1) >> (s[1] + 1) >> (s[2] + 1);
	string ns;
	L(t, 0, 2) L(i, 1, n * 2) cnt[t] += s[t][i] - '0';
	int g = (cnt[0] >= n) + (cnt[1] >= n) + (cnt[2] >= n);
	p[0] = p[1] = -1, tot[0] = tot[1] = 0;
	if(g >= 2) {
		L(t, 0, 2) if(cnt[t] >= n) {
			if(p[0] == -1) p[0] = t;
			else p[1] = t;
		}
		L(z, 0, 1) L(i, 1, n * 2) if(s[p[z]][i] == '1') t[z][++ tot[z]] = i;
		t[0][0] = t[1][0] = 0;
		t[0][n + 1] = t[1][n + 1] = 2 * n + 1;
		L(z, 0, n) {
			if(z) ns.push_back('1');
			L(j, t[0][z] + 1, t[0][z + 1] - 1) ns.push_back(s[p[0]][j]);
			L(j, t[1][z] + 1, t[1][z + 1] - 1) ns.push_back(s[p[1]][j]);
		}
	}
	else {
		L(t, 0, 2) if(cnt[t] <= n) {
			if(p[0] == -1) p[0] = t;
			else p[1] = t;
		}
		L(z, 0, 1) L(i, 1, n * 2) if(s[p[z]][i] == '0') t[z][++ tot[z]] = i;
		t[0][0] = t[1][0] = 0;
		t[0][n + 1] = t[1][n + 1] = 2 * n + 1;
		L(z, 0, n) {
			if(z) ns.push_back('0');
			L(j, t[0][z] + 1, t[0][z + 1] - 1) ns.push_back(s[p[0]][j]);
			L(j, t[1][z] + 1, t[1][z + 1] - 1) ns.push_back(s[p[1]][j]);
		}
	}
	while(sz(ns) < n * 3) ns.push_back('0');
	cout << ns << "\n"; 
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) rmain();
//	rmain();
	return 0;
}
/*
2
1
00
11
01
3
011001
110000
010001
*/