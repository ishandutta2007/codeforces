#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1007;
int T, n, m, a[N];
bool u[N], nw[N];
char s[N];
void Main() {
	cin >> n >> m >> (s + 1);
	memset(u, 0, sizeof(u));
	L(i, 1, n) u[i] = s[i] - '0';
	L(t, 1, min(m, n)) {
		L(j, 1, n) if(!u[j]) 
			nw[j] = u[j - 1] ^ u[j + 1];
		L(j, 1, n) u[j] |= nw[j], nw[j] = 0;
	}
	L(i, 1, n) cout << u[i];
	cout << "\n";
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) Main();
	return 0;
}