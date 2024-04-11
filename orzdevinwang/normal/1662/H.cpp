#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;

const int N = 1e5 + 7; 

ll w, l;
vi A; 
void slv(ll x) {
	L(msk, 0, (1 << 4) - 1) {
		int a = w - 2, b = l - 2, c = w - 2, d = l - 2;
		if(msk & 1) a += 1;
		else b += 1;
		if(msk & 2) b += 1;
		else c += 1;
		if(msk & 4) c += 1;
		else d += 1;
		if(msk & 8) d += 1;
		else a += 1;
		if(a % x == 0 && b % x == 0 && c % x == 0 && d % x == 0) {
			A.emplace_back(x);
			return ;
		}
	}
}
void Main() {
	cin >> w >> l;
	A.clear();
	ll s = 2 * (w + l - 2);
	L(i, 1, sqrt(s)) if(s % i == 0) {
		slv(i);
		if(i != s / i) slv(s / i);
	} 
	sort(A.begin(), A.end());
	cout << sz(A) << ' ';
	for(const int &u : A) cout << u << ' ';
	cout << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0; 
}