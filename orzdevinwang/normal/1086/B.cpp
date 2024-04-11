#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n, s, deg[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(12), cout << fixed;
	cin >> n >> s;
	L(i, 1, n - 1) {
		int a, b;
		cin >> a >> b;
		deg[a] += 1;
		deg[b] += 1;
	}
	int cnt = 0;
	L(i, 1, n) cnt += deg[i] == 1;
	cout << (double) s * 2 / cnt << '\n';
	return 0;
}