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
int n, k;
ll a[N];
void Main() {
	cin >> n >> k;
	L(i, n - k + 1, n) {
		cin >> a[i];
	}
	if(k == 1) {
		cout << "YES\n";
		return ;	
	}
	R(i, n, n - k + 2) {
		a[i] -= a[i - 1];
		if(i != n && a[i] > a[i + 1]) {
			cout << "NO\n";
			return ;
		}
	}
	if(a[n - k + 2] * (n - k + 1) < a[n - k + 1]) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}