#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define uint unsigned int 
using namespace std;
const int N = 1e3 + 7;
int n, a[N];
void swp (int x, int y) {
	swap (a[x], a[y]);
	cout << x << ' ' << y << '\n';
}
void solve (int n) {
	if (n <= 1) return ;
	solve (n - 4);
	R(i, n - 4, 1) swp (i, n - 3);
	swp (n - 3, n - 2);
	L(i, 1, n - 4) swp (i, n - 2);
	R(i, n - 4, 1) swp (i, n - 1);
	swp (n - 1, n);
	L(i, 1, n - 4) swp (i, n);
	swp (n - 3, n);
	swp (n - 2, n - 1);
	swp (n - 3, n - 1);
	swp (n - 2, n);
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	L(i, 1, n) a[i] = i;
	if(n % 4 == 2 || n % 4 == 3) return cout << "NO\n", 0;
	cout << "YES\n";
	solve (n);
	L(i, 1, n) assert (a[i] == i);
	return 0;
}