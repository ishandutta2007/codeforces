#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
ll n, m;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	if (n > 30) cout << m << '\n';
	else cout << m % (1 << n) << '\n';
	return 0;
}