#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define ld long double
#define i128 __int128 
using namespace std;
const int N = 1004;
int n, a[N];
void Main () {
	
	cin >> n ;
	L(i, 1, n) cin >> a[i];
	int ret = 0;
	L(i, 1, n) ret += a[i] - 1;
	cout << ((ret & 1) ? "errorgorn" : "maomao90 ") << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}