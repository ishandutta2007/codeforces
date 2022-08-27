#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1 << 20;
int n, a[N]; 
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) {
		bool ok = false;
		L(j, 2, i + 1) 
			if(a[i] % j) {
				ok = true;
				break ;
			}
		if(!ok) 
			return cout << "NO\n", void ();
	}
	cout << "YES\n";
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T ;
	while (T--) Main (); 
	return 0;
}