#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	int i = v0, cnt = 1;
	while (i < c)
		v0 += a, i += min(v1, v0) - l, cnt++;
	cout << cnt << endl;
	return 0;
}