#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	string s; cin >> s;
	int couA = 0, coua = 0;
	for (auto x : s) if (x <= 'z' and x >= 'a') coua++; else couA++;
	if (coua >= couA) {
		for (auto& x : s) if (x >= 'A' and x <= 'Z') {
			x -= 'A'; x += 'a';
		}
	}
	else for (auto& x : s) if (x >= 'a' and x <= 'z') {
		x -= 'a'; x += 'A';
	}
	cout << s;
}