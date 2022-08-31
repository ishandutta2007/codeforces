#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 1e6;
int n, a[N];
void Main() {
	ll sum = 0;
	cin >> n;
	int mid = n / 2;
	L(i, 1, n) a[i] = i;
	swap(a[1], a[n]), sum += n - 1, sum = (ll) (n - 1) * (n - 1);
	L(i, 2, mid) swap(a[i], a[n]), sum += (ll) (n - i) * (n - i);
	R(i, n - 1, mid + 1) swap(a[1], a[i]), sum += (ll) (i - 1) * (i - 1);
	cout << sum << "\n";
	L(i, 1, n) cout << a[i] << " ";
	cout << "\n" << n - 1 << "\n";
	L(i, mid + 1, n - 1) cout << i << " " << 1 << "\n";
	R(i, mid, 2) cout << i << " " << n << "\n";
	cout << 1 << " " << n << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}