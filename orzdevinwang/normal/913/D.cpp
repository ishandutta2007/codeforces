#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n, T, a[N], t[N];
vi S;
bool check(int x) {
	S.clear ();
	L(i, 1, n) if(a[i] >= x) S.push_back(i);
	sort(S.begin(), S.end(), [&] (int x, int y) {
		return t[x] < t[y];
	}) ;
	if(sz(S) < x) return false; 
	int ret = 0;
	L(i, 0, x - 1) ret += t[S[i]];
	return ret <= T;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> T ;
	L(i, 1, n) cin >> a[i] >> t[i];
	int l = 1, r = n, ns = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ns = mid, l = mid + 1;
		else r = mid - 1;
	}
	check (ns);
	cout << ns << '\n';
	cout << ns << '\n';
	L(i, 0, ns - 1) cout << S[i] << ' ';
	cout << '\n';
	return 0;
}