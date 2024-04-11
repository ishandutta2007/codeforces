#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll n;
vector<ld> x, v;

ld f(ld center) {
	ld ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, abs(center - x[i]) / v[i]);
	return ans;
}
int main() {    
    cin >> n;
    x = v = vector<ld>(n);
    for (auto &i : x) cin >> i;
    for (auto &i : v) cin >> i;
	ld l = -1e10, r = 1e10, EPS = 1e-6;
	while (r - l > EPS) {
	   ld m1 = l + (r - l) / 3,
	      m2 = r - (r - l) / 3;
	   if (f(m1) > f(m2))
	      l = m1;
	   else
	      r = m2;
	}
	cout << fixed << setprecision(20) << f(l);
    return 0;
}