#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(ll ku, ll shi, ll kat, ll m) {
	
	if (ku == m) {ku--;}
	else ku++;
	if (shi == m) {shi--;}
	else shi++;
	if (kat == m) {kat--;}
	else kat++;
	
	if (ku > shi && ku > kat) {cout << "Kuro"; return;}
	if (shi > ku && shi > kat) {cout << "Shiro"; return;}
	if (kat > shi && kat > ku) {cout << "Katie"; return;}
	
	cout << "Draw";
}

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector<ll> a(300), b(300), c(300);
	string x, y, z;
	cin >> x >> y >> z;
	for (int i = 0; i < x.size(); i++) {
		a[x[i]]++;
		b[y[i]]++;
		c[z[i]]++;
	}
	ll ku = 0, shi = 0, kat = 0;
	for (int i = 'A'; i <= 'Z'; i++) {
		ku = max(ku, a[i]);
		shi = max(shi, b[i]);
		kat = max(kat, c[i]);
	}
	for (int i = 'a'; i <= 'z'; i++) {
		ku = max(ku, a[i]);
		shi = max(shi, b[i]);
		kat = max(kat, c[i]);
	}
	
	ll m = x.size();
	
	if (n == 1) {
		solve(ku, shi, kat, m);
		return 0;
	}
	
	ll m1 = ku + n;
	ll m2 = shi + n;
	ll m3 = kat + n;
	
	if (m1 > m) ku = m;
	else ku = m1;
	
	if (m2 > m) shi = m;
	else shi = m2;
	
	if (m3 > m) kat = m;
	else kat = m3;
	
	if (ku > shi && ku > kat) {cout << "Kuro"; return 0;}
	if (shi > ku && shi > kat) {cout << "Shiro"; return 0;}
	if (kat > shi && kat > ku) {cout << "Katie"; return 0;}
	
	cout << "Draw";
	
	return 0;
}