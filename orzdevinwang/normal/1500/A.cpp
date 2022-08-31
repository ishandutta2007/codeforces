#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 5e6 + 7;
int n, m, q, a[N];
int x[N], y[N], g[N], p1, p2;
bool vis[N], cd[N]; 
void check(int i, int j) {
	int sum = a[i] + a[j];
	if(x[sum] && x[sum] != i && y[sum] != i && x[sum] != j && y[sum] != j) {
		cout << "YES\n";
		cout << x[sum] << " " << y[sum] << " " << i << " " << j << "\n";
		exit(0);
	}
	x[sum] = i, y[sum] = j;
}
void Main() {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) L(j, 1, i - 1) check(i, j);
	cout << "NO\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main();
	return 0;
}