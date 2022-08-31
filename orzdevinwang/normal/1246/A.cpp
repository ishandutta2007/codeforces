#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 6e5 + 7;
ll n, p;
int main () {
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	cin >> n >> p;
	L(z, 1, 1000) {
		ll w = n - (ll) p * z;
		if(w < z) continue;
		int cnt = 0;
		L(i, 0, 30) cnt += w >> i & 1;
		if(z < cnt) continue;
		cout << z << '\n';
		return 0;
	}
	cout << -1 << '\n';
	return 0;
}