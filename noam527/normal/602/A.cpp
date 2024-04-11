#include <iostream>
#include <algorithm>
#include <vector>
#define last(X) (X)[(X).size() - 1]
typedef long long ll;
using namespace std;

ll n, b, v1 = 0, v2 = 0, t;

int main() {
	cin >> n >> b;
	for (int i = 0; i < n; i++) cin >> t, v1 = v1 * b + t;
	cin >> n >> b;
	for (int i = 0; i < n; i++) cin >> t, v2 = v2 * b + t;
	if (v1 < v2) cout << "<" << endl;
	else if (v1 > v2) cout << ">" << endl;
	else cout << "=" << endl;
	return 0;
}