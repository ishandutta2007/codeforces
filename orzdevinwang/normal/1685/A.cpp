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
int n, a[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(n & 1) return cout << "NO\n", void ();
	L(i, 2, n / 2) if(a[i] == a[i + n / 2 - 1]) 
		return cout << "NO\n", void ();
	cout << "YES\n";
	L(i, 1, n / 2) {
		cout << a[i] << ' ' << a[i + n / 2] << ' ';
	}
	cout << '\n';
} 
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t ;
	cin >> t;
	while(t--) Main();
	return 0;
}