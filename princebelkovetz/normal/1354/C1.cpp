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
	int n; cin >> n;
	n *= 2;
	const double PI = acos(-1.0);
	long double ans = 1.0 / (2 * (sin(PI / n)));
	ans *= cos(PI / n);
	cout << 2 * ans << endl;
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