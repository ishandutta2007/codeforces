#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define mkp make_pair
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7;
int n, m, f[N];
int rmain() {
	cin >> n >> m;
	if(m * 2 + 1 > n) return cout << "-1\n", 0;
	int tot = n;
	L(i, 1, n) f[i] = 0;
	L(i, 1, m) f[i * 2] = tot, --tot;
	L(i, 1, n) if(!f[i]) f[i] = tot, --tot;
	L(i, 1, n) cout << f[i] << " ";
	cout << "\n"; 
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) rmain();
	return 0;
}