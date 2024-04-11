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
	cin >> n >> m;
	int sumx = 0, sumy = 0, cnt = 0;
	L(i ,1, n) cin >> (s[i] + 1); 
	L(i, 1, n) {
		L(j, 1, m) if(s[i][j] == 'B') {
			sumx += i;
			sumy += j;
			cnt += 1;
		}
	}
	cout << sumx / cnt << ' ' << sumy / cnt << '\n';
	return 0;
}