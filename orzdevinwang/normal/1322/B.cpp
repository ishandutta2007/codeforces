#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20;
int n, a[N], c[N], ret;
char s[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 1, n) cin >> a[i], ret ^= a[i];
	if(n & 1) ret = 0;
	L(t, 0, 30) {
		L(i, 1, n) c[i] = a[i] & ((1 << t) - 1);
		sort(c + 1, c + n + 1);
		L(i, 1, n) {
			int orz = lower_bound(c + i + 1, c + n + 1, (1 << t) - c[i]) - c;
			orz = n + 1 - orz;
			if(orz & 1) 
				ret ^= 1 << t;
		}
	}
	cout << ret << '\n';
	return 0;
}