#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 5007, mod = 998244353;
int n, m, a[N], f[N], A[N], B[N];
char s[N][N]; 
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	L(i, 1, 1000) cout << (i & 1 ? 4 : 5);
	cout << 5 << '\n';
	L(i, 1, 1000) cout << (i & 1 ? 5 : 4);
	cout << 5 << '\n';
	return 0;
}