#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1007;
int T, n, a[N];
void Main() {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	cout << n * 3 << "\n";
	L(a, 1, n / 2) {
		int i = a * 2 - 1, j = a * 2;
		cout << 1 << " " << i << " " << j << "\n";
		cout << 2 << " " << i << " " << j << "\n";
		cout << 1 << " " << i << " " << j << "\n";
		cout << 2 << " " << i << " " << j << "\n"; 
		cout << 1 << " " << i << " " << j << "\n";	
		cout << 2 << " " << i << " " << j << "\n"; 
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) Main();
	return 0;
}