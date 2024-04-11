#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, c, d;
void Main () {
	cin >> c >> d;
	if(c == 0 && d == 0) cout << 0 << "\n";
	else if((c + d) & 1) cout << -1 << "\n";
	else if(c == d) cout << 1 << "\n";
	else cout << 2 << "\n";
}
int main () {
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}