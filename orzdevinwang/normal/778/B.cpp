#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m, g[N];
int A[N], B[N], op[N];
map<string, int> mp;
string s, G, tmp, f[N], ansa, ansb;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) {
		cin >> s >> tmp >> G;
		mp[s] = i;
		if(G[0] <= '1' && G[0] >= '0') f[i] = G, op[i] = -1;
		else {
			if(G[0] == '?') A[i] = n + 1;
			else A[i] = mp[G];
			cin >> G;
			if(G[0] == 'X') op[i] = 0;
			if(G[0] == 'O') op[i] = 1;
			if(G[0] == 'A') op[i] = 2;
			cin >> G;
			if(G[0] == '?') B[i] = n + 1;
			else B[i] = mp[G];
		}
	}
	L(t, 0, m - 1) {
		int suma = 0, sumb = 0;
		g[n + 1] = 0;
		L(i, 1, n) {
			if(op[i] == -1) g[i] = f[i][t] - '0';
			if(op[i] == 0) g[i] = (g[A[i]] ^ g[B[i]]);
			if(op[i] == 1) g[i] = (g[A[i]] | g[B[i]]);
			if(op[i] == 2) g[i] = (g[A[i]] & g[B[i]]);
			suma += g[i];
		}
		g[n + 1] = 1;
		L(i, 1, n) {
			if(op[i] == -1) g[i] = f[i][t] - '0';
			if(op[i] == 0) g[i] = (g[A[i]] ^ g[B[i]]);
			if(op[i] == 1) g[i] = (g[A[i]] | g[B[i]]);
			if(op[i] == 2) g[i] = (g[A[i]] & g[B[i]]);
			sumb += g[i];
		}
		if(suma == sumb) ansa.push_back('0'), ansb.push_back('0');
		else if(suma > sumb) ansa.push_back('1'), ansb.push_back('0');
		else ansa.push_back('0'), ansb.push_back('1');
	}
	cout << ansa << endl << ansb << endl;
	return 0;
}