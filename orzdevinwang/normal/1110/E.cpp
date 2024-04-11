#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7; 
int n, m, c[N], t[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> c[i];
	L(i, 1, n) cin >> t[i];
	if(c[1] != t[1] || c[n] != t[n]) return cout << "No\n", 0;
	L(i, 1, n) c[i] -= c[i + 1], t[i] -= t[i + 1];
	sort(c + 1, c + n);
	sort(t + 1, t + n);
	L(i, 1, n) if(c[i] != t[i]) return cout << "No\n", 0;
	cout << "Yes\n";
	
	return 0;
}