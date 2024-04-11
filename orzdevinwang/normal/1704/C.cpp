#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7;
int n, m, x, a[N];
int arr[N], xn;
void Main() {
	cin >> n >> m;
	L(i, 1, m) cin >> a[i];
	sort(a + 1, a + m + 1);
	xn = 0;
	L(i, 1, m - 1) 
		if(a[i + 1] - a[i] != 1) 
			arr[++xn] = a[i + 1] - a[i] - 1;
	if(!(a[1] == 1 && a[m] == n)) 
		arr[++xn] = a[1] + n - a[m] - 1;
	sort(arr + 1, arr + xn + 1);
//	L(i, 1, xn) cout << arr[i] << ' ';
//	cout << '\n';
	int cur = 0, ns = 0;
	R(i, xn, 1) {
		int w = arr[i] - cur * 2;
		if(w == 1) ns += 1;
		else if(w >= 2) ns += w - 1;
		cur += 2;
	}
	cout << n - ns << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}