#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, a[N], cnt[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) {
		L(j, 0, 29) {
			if(a[i] >> j & 1) 
				cnt[j] += 1;
		}
	}
	int g = 0;
	L(i, 0, 29) g = __gcd (g, cnt[i]);
	L(i, 1, n) if(g % i == 0) 
		cout << i << ' ';
	cout << '\n';
	L(i, 0, 29) cnt[i] = 0;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}