#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7, O = 5e5;
int n, k, a[N];
void Main() {
	cin >> n >> k;
	ll ns = 0;
	L(i, 1, n) cin >> a[i], ns += a[i];
	L(i, 1, n) a[i] -= n - i + 1;
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	L(i, 1, k) ns -= a[i];
	ns -= (ll) k * (k + 1) / 2; 
	cout << ns << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}

/*
1
7 
0010110
*/