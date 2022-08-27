#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
int n, a[N];
void Main () {
	cin >> n;
	L(i, 2, n + 1) cout << i << ' ' ;
	cout << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t;
	cin >> t;
	while (t--) Main ();
	return 0;
}