#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 4e5 + 7;
int n, b[N];
ll a[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> b[i];
	ll c = 0;
	L(i, 1, n) a[i] = c + b[i], c = max(c, a[i]), cout << a[i] << ' ';
	cout << '\n';
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Main ();
//	int T;
//	cin >> T;
//	while (T--) Main ();
	return 0;
}