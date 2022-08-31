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
int n;
ll a[N], c[N];
/*
*/
void Main() {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) c[i] = a[i] + c[i - 1];
	if(c[n] != 0) return cout << "NO\n", void();
	L(i, 1, n) if(c[i] < 0) return cout << "NO\n", void(); 
	L(i, 2, n) if(c[i - 1] == 0 && c[i] != 0) return cout << "NO\n", void();
	cout << "YES\n";
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}