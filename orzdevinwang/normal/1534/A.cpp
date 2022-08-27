#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e2 + 7;
int n, m;
char s[N][N];
void Main() {
	cin >> n >> m;
	L(i, 1, n) cin >> (s[i] + 1);
	int op = -1;
	L(i, 1, n) L(j, 1, m) if(s[i][j] != '.') {
		int o = (s[i][j] == 'R');
		o ^= ((i + j) & 1);
		if(o == op || op == -1) op = o;
		else return cout << "NO\n", void();
	}
	if(op == -1) op = 0;
	cout << "YES\n";
	L(i, 1, n) {
		L(j, 1, m) cout << ((((i + j) & 1) ^ op) ? 'R' : 'W');
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}