#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 1e6 + 7; 
int n, m, a[N];
bool chk(int x) {
	L(i, 2, sqrt (x)) if(x % i == 0) return true;
	return false;
}
void Main () {
	cin >> n ;
	L(i, 1, n) {
		cin >> a[i];
	}
	ll sum = 0;
	L(i, 1, n) {
		sum += a[i];
	}
	if(chk(sum)) {
		cout << n << '\n';
		L(i, 1, n) cout << i << ' ';
		cout << '\n';
		return ;
	}
	L(i, 1, n) {
		ll sum = 0;
		L(j, 1, n) if(i != j) sum += a[j];
		if(chk(sum)) {
			cout << n - 1 << '\n';
			L(j, 1, n) if(j != i) cout << j << ' ';
			cout << '\n';
			return ;
		}
	}
	assert (0);
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}