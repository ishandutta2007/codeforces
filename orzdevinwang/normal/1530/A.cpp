#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 3e5 + 7;
int n, m; 
void Main () {
	cin >> n;
	int mx = 0;
	while (n) {
		mx = max(mx, n % 10);
		n /= 10;
	}
	cout << mx << "\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main(); 
	return 0;
}