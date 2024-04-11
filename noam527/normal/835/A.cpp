#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define last(X) (X)[(X).size() - 1]
#define last(x, y) (x)[(x).size() - y]
typedef long long ll;
using namespace std;

int s, v1, v2, t1, t2, tot1, tot2;

int main() {
	ios::sync_with_stdio(0);
	cin >> s >> v1 >> v2 >> t1 >> t2;
	tot1 = v1 * s + 2 * t1, tot2 = v2 * s + 2 * t2;
	if (tot1 < tot2) cout << "First" << endl;
	else if (tot1 > tot2) cout << "Second" << endl;
	else cout << "Friendship" << endl;
}