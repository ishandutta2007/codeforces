#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;
void solve(){
	long double n; cin >> n;
	n *= 2;
	const double PI = acos(-1.0);
	long double ans1 = 1.0 / (2.0 * (sin(PI / n / 2)));
	long double ans2 = ans1 * cos(PI / n);
	cout << ans1 << endl;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	cin >> t;
	while (t--){
		solve();
	}
 
}