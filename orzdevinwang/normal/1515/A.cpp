#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
#define i128 __int128
using namespace std;
const int N = 1e6 + 7;
int T, n, x, a[N], b[N];
void Main() {
	cin >> n >> x;
	L(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int sum = 0;
	L(i, 1, n) {
		sum += a[i];
		if(sum == x) {
			if(i != n) swap(a[i], a[n]);
			else return cout << "NO\n", void();
		}
	}
	cout <<"YES\n";
	L(i, 1, n) cout << a[i] << " ";
	cout <<"\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) Main();
	return 0;
}