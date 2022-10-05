#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	bool cw = false, ccw = false;
	char st, en;
	int n, s, e, map[200];
	map['^'] = 0, map['>'] = 1, map['v'] = 2, map['<'] = 3;
	cin >> st >> en >> n;
	s = map[st], e = map[en];
	if ((s + n) % 4 == e) cw = true;
	if ((s + 2000000000 - n) % 4 == e) ccw = true;
	if (cw && ccw) cout << "undefined" << endl;
	else if (cw) cout << "cw" << endl;
	else cout << "ccw" << endl;
	return 0;
}